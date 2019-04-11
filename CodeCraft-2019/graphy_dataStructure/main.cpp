#include "graph.hpp"


int main(int argc, char *argv[])
{	int ins = 0;
	GraphLink graphy;
	char vert[5] = {'a', 'b', 'c', 'd', 'e'};
	for(int i = 0; i < 5; i++)
	{
		graphy.InsertVertex(vert[i]);
	}
	for(int i = 0; i < 10; i++)
	{
		char a = getchar();
		if( a == 's')
		{
			break;// char a = getchar();
		}
		char b = 'a';
		graphy.InsertEdge(b,a);		
		cout << ins++ << endl;
	}
	graphy.Show();
	return -1;
}