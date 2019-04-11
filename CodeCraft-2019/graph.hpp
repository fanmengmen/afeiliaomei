#include <iostream>
using namespace std;
 
#define SIZE 10
struct Edge
{
	Edge(int v):destvalue(v),link(NULL){}
	int destvalue;
	Edge *link;
};
struct Vertex
{
	Vertex():list(NULL){}
	int data;
	Edge *list;
};
class GraphLink
{
public:   
	GraphLink(int v);
    void InsertVertex(int v);
	int GetVertexI(int v);
    int InsertEdge(int v1,int v2);
    void Show();
    void DeleteEdge(int v1,int v2);
    void DeleteVertex(int v);
	bool getMaxV(int v);
	void getNum(int v);
    ~GraphLink();
public:
	int MaxVertex;
	int NumVertex;
	int NumEdge;
	Vertex *VertexTable;
};