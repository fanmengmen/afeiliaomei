#include <iostream>
#include "simulation.hpp"

using namespace std;

//#define SIZE 10

struct Edge
{
    Edge(int v):destvalue(v), link(NULL){}
    int destvalue;
    Edge *link;
    /* data */
};

struct Vertex
{
    Vertex():list(NULL){}
    struct cross data;
    Edge *list;
    /* da
    ta */
};

class graphy
{

public:
    graphy(/* args */);
    void setMaxVertex(int size);
    int insertVertex(struct cross v);
    int getVertex(struct cross v);
    int insertEdge(struct cross v1, struct cross v2);
    void show();
    void deleteEdge(struct cross v1, struct cross v2);
    void deleteVertex(struct cross v);
    void creatGraphy(struct cross listCross[], struct road listRoad[]);
    void dfs(struct cross listCross[], struct car listCar[], struct road listRoad[]);
    int roadVertex(struct road roadVertex[], int roadNum, int roadSize);
	//get the roads' dest to connect the next cross
    ~graphy();

private:
    int MaxVertex;
    int NumVertex;
    int NumEdge;
    Vertex *vertexTable;
};








