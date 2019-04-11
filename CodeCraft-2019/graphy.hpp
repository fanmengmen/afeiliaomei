#include "simulation.hpp"

using namespace std;

//#define SIZE 10

typedef struct Edge
{
    Edge(int v):link(NULL),destvalue(v){}
    int destvalue;
    Edge *link;
    ~Edge(){}
    /* data */
};

typedef struct Vertex
{
    Vertex(cross data):list(NULL),data(data){}
    struct cross data;
    Edge *list;
    ~Vertex(){}
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

public:
    int MaxVertex;
    int NumVertex;
    int NumEdge;
    Vertex *vertexTable;
    Edge* ed;
};








