#include "iostream"
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;


struct cross
{
	int cross_id;
	int road_id[4];
};

struct road
{
	int road_id;
	int road_len;
	int init_id;
	int dest_id;
	int re_speed;
	int lanes_num;//number of lanes(chedao)
	bool istwoway;
	int node[10];
};

struct car
{
	int car_id;
	int init;
	int dest;
	int max_car;
	int start_time;
	int turn[100][3];//0: go straight, 1: turn left, 2: turn right
}; 
class simulation
{
public:
    int car_id;
	int crossSize;
	int roadSize;
	int carSize;
    /* data */
public:
    simulation(/* args */);
    ~simulation();
    bool isStart(int t, int value);
    //judge whether it is time to leave
	int getCrossSize();
	int getRoadSize();
	int getCarSize();
	//get the size of crosslist, roadlist and car list, then storge them in a array
    void meetCross();
    //
    void readData(struct cross listCross[], struct car listCar[], struct road listRoad[]);
    //read data from the txt files
    void roadInitial();
    //divide the road to different grid accoarding to the velocity restiction
	
	
};



