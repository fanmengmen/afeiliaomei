#include "simulation.hpp"
#include <eigen3/Eigen/Dense>
#include <math.h>

simulation::simulation(/* args */)
{
}

simulation::~simulation()
{
}

bool simulation::isStart(int t, int value)
{
	if(t == value)
		return true;
	return false;
}

int simulation::readData(struct cross listCross[100], struct car listCar[200], struct road listRoad[200])
{
	
	string line; 
	string substr;
	int num = 0;
	//int space[10];
	int comma[10];
	fstream f("../config/cross.txt");
	while (getline(f, line))
	{	
		//int count_space = 0;
		int count_comma = 0;
		std::size_t i = 0;
		if(line[0] != '#')
		{	
			while(i < line.length())
			{
				/*if(line.at(i) == ' ')
				{
					space[count_space] = i;	
					count_space ++;
				}	
				else*/
				if(line.at(i) == ',')
				{
					comma[count_comma] = i;
					count_comma ++;
				}
				i++;
			}
			listCross[num].cross_id = stoi(line.substr(1, comma[0]-1),0,10);
			listCross[num].road_id[0] = stoi(line.substr(comma[0]+2, comma[1]-1),0,10);
			listCross[num].road_id[1] = stoi(line.substr(comma[1]+2, comma[2]-1),0,10);
			listCross[num].road_id[2] = stoi(line.substr(comma[2]+2, comma[3]-1),0,10);
			listCross[num].road_id[3] = stoi(line.substr(comma[3]+2, line.length() - 2),0,10);
			num++;
		}
		
	}
	crossSize = num;
	//cout << crossSize << endl;
	f.close();

	fstream road_txt("../config/road.txt");
	num = 0;
	line.erase();
	while (getline(road_txt, line))
	{	
		
		//int count_space = 0;
		int count_comma = 0;
		std::size_t i = 0;
		if(line[0] != '#')
		{	
			while(i < line.length())
			{
				/*if(line.at(i) == ' ')
				{
					space[count_space] = i;	
					count_space ++;
				}	
				else*/ 
				if(line.at(i) == ',')
				{
					comma[count_comma] = i;
					count_comma ++;
				}
				i++;
			}
			listRoad[num].road_id = stoi(line.substr(1, comma[0]-1),0,10);
			listRoad[num].road_len = stoi(line.substr(comma[0]+2, comma[1]-1),0,10);
			listRoad[num].re_speed = stoi(line.substr(comma[1]+2, comma[2]-1),0,10);
			listRoad[num].lanes_num = stoi(line.substr(comma[2]+2, comma[3]-1),0,10);
			listRoad[num].init_id = stoi(line.substr(comma[3]+2, comma[4]-1),0,10);
			listRoad[num].dest_id = stoi(line.substr(comma[4]+2, comma[5]-1),0,10);
			listRoad[num].istwoway = stoi(line.substr(comma[5]+2, line.length() - 2),0,10);
			//std::cout << line << endl;
			//std::cout << listRoad[num].road_id << endl;

			num++;
		}
		
	}
	roadSize = num;
	road_txt.close();

	fstream car_txt("../config/car.txt");
	num = 0;
	line.erase();
	while (getline(car_txt, line))
	{	
		//int count_space = 0;
		int count_comma = 0;
		std::size_t i = 0;
		if(line[0] != '#')
		{	
			while(i < line.length())
			{
				/*if(line.at(i) == ' ')
				{
					space[count_space] = i;	
					count_space ++;
				}	
				else*/ 
				if(line.at(i) == ',')
				{
					comma[count_comma] = i;
					count_comma ++;
				}
				i++;
			}
			listCar[num].car_id = stoi(line.substr(1, comma[0]-1),0,10); 
			listCar[num].init = stoi(line.substr(comma[0]+2, comma[1]-1),0,10);
			listCar[num].dest = stoi(line.substr(comma[1]+2, comma[2]-1),0,10);
			listCar[num].max_car = stoi(line.substr(comma[2]+2, comma[3]-1),0,10);
			listCar[num].start_time = stoi(line.substr(comma[3]+2, line.length() - 2),0,10);
			num++;
			//std::cout << line << endl;
			//std::cout << listRoad[num].lanes_num << endl;
		}
		
	}
	carSize = num;
	car_txt.close();
	return 1;
}

int simulation::getCrossSize()
{
	return crossSize;
}
int simulation::getRoadSize()
{
	return roadSize;
}
int simulation::getCarSize()
{
	return carSize;
}
int simulation::roadVertex(struct road roadVertex[], int roadNum, int roadSize)
{
	for(int i = 0; i < roadSize; i++)
	{   
        //cout << roadVertex[i].road_id << endl;  
		if(roadVertex[i].road_id == roadNum)
			return roadVertex[i].dest_id;
	}
    return -1;
}

void simulation::roadInitial()
{
	
}



void cameraToWorld(float yaw, float pitch, float roll, float positionUAV[3] ,float positionCamera[3], float positionWorld[3])
{
	Eigen::Matrix3f Rotation;
	Eigen::Vector3f positionC;
	Eigen::Vector3f positionW;
	Eigen::Vector3f positionD;
	
	for(int i = 0; i < 3; i++)
	{
		positionD(i) = positionUAV[i];
		positionC(i) = positionCamera[i];
	}

	//creat the rotation matrix
	Rotation(0,0) = cos(yaw)*cos(pitch);
	Rotation(0,1) = cos( yaw)*sin( roll)*sin( pitch) - cos( roll)*sin( yaw);
	Rotation(0,2) = sin( yaw)*sin( roll) + cos( yaw)*cos( roll)*sin( pitch);
	Rotation(1,0) = cos( pitch)*sin( yaw);
	Rotation(1,1) = cos( yaw)*cos( roll) + sin( yaw)*sin( roll)*sin( pitch);
	Rotation(1,2) = cos( roll)*sin( yaw)*sin( pitch) - cos( yaw)*sin( roll);
	Rotation(2,0) = - sin( pitch);
	Rotation(2,1) = cos( pitch)*sin( roll);
	Rotation(2,2) = cos( roll)*cos( pitch);

	positionW = Rotation * positionC + positionD;

	for(int i = 0; i < 3; i++)
		positionWorld[i] = positionW(i);
	

}