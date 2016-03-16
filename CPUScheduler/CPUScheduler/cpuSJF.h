#ifndef SJF_H
#define SJF_H
#include "list.h"

class SJF
{
public:
	SJF() :CPUnode(0), counter(0), idle(0), utilization(0) { queue = make_shared<list>(); };
	~SJF() {	};
	void start();										//controlls the flow of the class


private:
	shared_ptr<list> queue;								//this is the ready queue
	shared_ptr<listnode>CPUnode;						//this is the node running on the cpu
	shared_ptr<list> IO = make_shared<list>();			//this is the io queue
	shared_ptr<list> finished = make_shared<list>();	//this is the list of finished processes
	void CPU_SJF();										//shortest time first
	void do_IO();										//run io list
	void do_CPU();										//run cpu list
	void init();										//set up the lists
	void print();										//print important list data
	void waiting_time();								//increment turnaround, waiting time, response time
	int counter;										//keeps time of the program
	int idle;											//keeps track of cpu idle time
	double utilization;									//the utilazion of the cpu. counter vs idle
};
#endif