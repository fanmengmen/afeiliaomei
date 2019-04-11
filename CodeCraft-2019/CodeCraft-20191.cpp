#include "graphy.hpp"
#include <new>
#include <stdio.h>
int mains(int argc, char *argv[])
{
    std::cout << "Begin" << std::endl;
	// float yaw = 0.4;
	// float pitch= 0.4;
	// float roll = 0.4;
	// float positionUAV[3] = {1, 2, 3};
	// float positionCamera[3] = {1, 1, 1};
	// float positionWorld[3];
	// cameraToWorld(yaw, pitch, roll, positionUAV , positionCamera, positionWorld);
	// cout << "x: " << positionWorld[0] << "y: " << positionWorld[1] << "z: " << positionWorld[2] <<endl;
	// // if(argc < 5){
	// 	std::cout << "please input args: carPath, roadPath, crossPath, answerPath" << std::endl;
	// 	//exit(1);
	// }
	simulation sim;
	graphy traffic;
	struct cross listCross[100];
	struct road listRoad[200];
	struct car listCar[200];
	struct cross markCross;
	int mark;
	int edges, nodes;
	cout << "is read susscefully? " << sim.readData(listCross, listCar, listRoad) << endl;
	// getchar();
	// creat the graphy consisited of cross(vertex) and road(edge)
	traffic.setMaxVertex(sim.getCrossSize());
	cout << "size" << sim.getCrossSize() << endl;
	for(int i = 0; i < sim.getCrossSize(); i++)
    {
        nodes = traffic.insertVertex(listCross[i]);
		cout << "nodes: " << nodes << endl;
	}	
    // int *ed = new int(12);//error
	for(int i = 0; i < sim.getCrossSize(); i++)
    {
		markCross = listCross[i];
		for(int j = 0; j < 4; j++)
		{
			if(listCross[i].road_id[j] != -1)
			{	
				//cout << "tests " << listCross[i].road_id[j] << endl;//test
				//for every edge of a node, we set the mark as the last node of a pointer 
				mark = traffic.roadVertex(listRoad, listCross[i].road_id[j], sim.getRoadSize());
				if(mark == -1)
					continue; 
				//getchar();
				edges = traffic.insertEdge(markCross, listCross[mark]);
				cout << "edges: " << edges << endl;
				markCross = listCross[mark];
			}
		}
        
    }
	
	traffic.show();

	//ergodic the graphy 

	/*std::string carPath(argv[1]);
	std::string roadPath(argv[2]);
	std::string crossPath(argv[3]);
	std::string answerPath(argv[4]);
	
	std::cout << "carPath is " << carPath << std::endl;
	std::cout << "roadPath is " << roadPath << std::endl;
	std::cout << "crossPath is " << crossPath << std::endl;
	std::cout << "answerPath is " << answerPath << std::endl;
	*/
	// TODO:read input filebuf
	// TODO:process
	// TODO:write output file
	return -1;
}