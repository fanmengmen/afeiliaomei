#include "graph.hpp"
#include "simulation.hpp"


int main(int argc, char *argv[])
{	
	simulation sim;
	struct cross listCross[100];
	struct road listRoad[200];
	struct car listCar[200];
	struct cross markCross;
	//read the txt data
	sim.readData(listCross, listCar, listRoad);

	int ins = 0;
	// sim.getCrossSize();
	GraphLink *graphy = new GraphLink(sim.getCrossSize());
	cout << "size of vertex: " << graphy -> MaxVertex <<  endl;
	//insert the vertex
	for(int i = 0; i < graphy -> MaxVertex; i++)
	{
		graphy -> InsertVertex(listCross[i].cross_id);
	}
	//insert the edge
	for(int i = 0; i < sim.roadSize; i++)
	{
		//cout << "init: " << listRoad[i].init_id << "dest: " << listRoad[i].dest_id << endl;
		graphy -> InsertEdge(listRoad[i].init_id, listRoad[i].dest_id);
	}
	//test edge insert by inputing
	// for(int i = 0; i < 10; i++)
	// {
	// 	char a = getchar();
	// 	if( a == 's')
	// 	{
	// 		break;// char a = getchar();
	// 	}
	// 	char b = 'a';
	// 	graphy -> InsertEdge(b,a);		
	// 	cout << ins++ << endl;
	// } 
	graphy -> Show();

	cout << "size of edges" << graphy -> NumEdge << endl;
	//遍历
	
	return -1;
}