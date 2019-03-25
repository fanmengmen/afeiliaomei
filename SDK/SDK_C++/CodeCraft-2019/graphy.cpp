#include "graphy.hpp"

graphy::graphy(/* args */)
{
    MaxVertex;
    NumVertex = NumEdge = 0;
    vertexTable = new Vertex[MaxVertex];
}

graphy::~graphy()
{
    /*Edge *p = NULL;
    for(int i = 0; i < NumVertex; i++)
    {
        p = vertexTable[i].list;
        while(p)
        {
            vertexTable[i].list = p -> link;
            delete p;
            p = vertexTable[i].list;
        }
        delete []vertexTable;
        vertexTable = NULL;
    }*/
}
void graphy::setMaxVertex(int size)
{
    MaxVertex = size;
}
int graphy::insertVertex(struct cross v)
{
    if(NumVertex > MaxVertex)
        return -1;
    vertexTable[NumVertex].data = v;
    NumVertex++;
    return NumVertex;
}

int graphy::getVertex(struct cross v)
{
    for(int i = 0; i < NumVertex; i++)
    {
        //must use id to compare, not the struct
        if (vertexTable[i].data.cross_id == v.cross_id)
            return i;
    }
    return -1;
}

int graphy::insertEdge(struct cross v1, struct cross v2)
{
    int p1 = getVertex(v1);
    int p2 = getVertex(v2);
    cout << "p1: " << p1 << "p2: " << p2 << endl;
    if(p1 == -1 || p2 == -1)
        return 0;
    //p1 -> p2 directed graphy only have one direction of one edge
    //getchar();
    Edge *ed = new Edge(p2);
    ed -> link = vertexTable[p1].list;
    vertexTable[p1].list = ed;

   
    //p2 ->p1
    ed = new Edge(p1);
    ed -> link = vertexTable[p2].list;
    vertexTable[p2].list = ed;
    
    
    NumEdge++;
    return NumEdge;
}

void graphy::show()
{
    int i;
    for(i = 0; i < NumVertex; i++)
    {
        cout << vertexTable[i].data.cross_id << " -> ";
        Edge *p = vertexTable[i].list;
        while(p)
        {
            cout << p -> destvalue << " -> ";
            p = p -> link;
        }
        cout << "null" <<endl;
    }
}

void graphy::deleteEdge(struct cross v1, struct cross v2)
{
    int p1 = getVertex(v1);
    int p2 = getVertex(v2);
    if(p1 == -1 || p2 == -1)
        return;
    //delete p1 ->p2
    Edge *p = vertexTable[p1].list;
    Edge *s = NULL;
    while(p && p -> destvalue != p2)
    {
        s = p;
        p = p ->link;
    }
    if(p == NULL)
        return;
    if(s == NULL)
        vertexTable[p1].list = p->link;
    else
        s->link = p->link;
    delete p; 

    //delete p2->p1
   /* p =vertexTable[p2].list;
		s = NULL;
		while(p && p->destvalue != p1)
		{
			s = p;
			p = p->link;
		}
		if(s == NULL)
			vertexTable[p2].list = p->link;
		else
			s ->link = p->link;
		delete p;
		p = NULL;*/
		NumEdge--;      
}

void graphy::deleteVertex(struct cross v)
{
    int p = getVertex(v);
    if(p == -1)
        return;
    //delete the relative edge to the vertex
    Edge *s = NULL;
    Edge *edp = vertexTable[p].list;
    while(edp)
    {
        int destvalue = edp -> destvalue;
        Edge *q = vertexTable[destvalue].list;
        s = NULL;
        while(q && q -> destvalue != p)
        {
                s = q;
                q = q -> link;
        }
        if(s == NULL)
        vertexTable[destvalue].list = q -> link;
        else
        {
            s -> link = q -> link;
        }
        delete q;
        q = NULL;
        vertexTable[p].list = edp ->link;
        delete edp;
        edp = vertexTable[p].list;
        NumEdge --;   
    }
    //delete vertex
    NumVertex --;
    vertexTable[p].data = vertexTable[NumVertex].data;
    vertexTable[p].list = vertexTable[NumVertex].list;
    edp = vertexTable[p].list;
    while(edp)
    {
        int destvalue = edp -> destvalue;
        s = vertexTable[destvalue].list;
        while(s && destvalue != NumVertex)
            s = s -> link;
        s -> destvalue = p;
        edp = edp -> link;
    }
    
}

int graphy::roadVertex(struct road roadVertex[], int roadNum, int roadSize)
{
	for(int i = 0; i < roadSize; i++)
	{   
        //cout << roadVertex[i].road_id << endl;  
		if(roadVertex[i].road_id == roadNum)
			return roadVertex[i].dest_id - 1;
	}
    return -1;
}


void dfs(struct cross listCross[], struct car listCar[], struct road listRoad[])
{

}

void graphy::creatGraphy(struct cross listCross[], struct road listRoad[])
{
    
}
