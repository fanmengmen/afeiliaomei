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
	char data;
	Edge *list;
};
class GraphLink
{
public:
    GraphLink();
    void InsertVertex(char v);
	int GetVertexI(char v);
    void InsertEdge(char v1,char v2);
    void Show();
    void DeleteEdge(char v1,char v2);
    void DeleteVertex(char v);
    ~GraphLink();
private:
	int MaxVertex;
	int NumVertex;
	int NumEdge;
	Vertex *VertexTable;
};