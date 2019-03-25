#include "graphy.hpp"



int main(int argc, char *argv[])
{
    std::cout << "Begin" << std::endl;
	
	if(argc < 5){
		std::cout << "please input args: carPath, roadPath, crossPath, answerPath" << std::endl;
		//exit(1);
	}
	simulation sim;
	struct cross listCross[100];
	struct road listRoad[1000];
	struct car listCar[1000];
	sim.readData(listCross, listCar, listRoad);
	//creat the graphy consisited of cross(vertex) and road(edge)
	graphy traffic;
	traffic.setMaxVertex(sim.getCrossSize());
	int mark;
	int edges, nodes;
	cout << "size" << sim.getCrossSize() << endl;
	//getchar();
	for(int i = 0; i < sim.getCrossSize(); i++)
    {
        nodes = traffic.insertVertex(listCross[i]);
		cout << "nodes: " << nodes << endl;
	}
	struct cross markCross;
	
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
				cout << mark << endl;
				if(mark == -1)
					continue; 
				getchar();
				edges = traffic.insertEdge(markCross, listCross[mark]);
				cout << "edges: " << edges << endl;
				markCross = listCross[mark];
			}
		}
        
    }

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