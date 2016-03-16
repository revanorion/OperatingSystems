#ifndef ML_H
#define ML_H
#include "list.h"

class ML
{
public:
	ML() :CPUnode(0), counter(0), idle(0), utilization(0) { queue = make_shared<list>();};
	~ML() {	};
	void start();										//controlls the flow of the class


private:
	shared_ptr<list> queue;								//this is the ready queue
	shared_ptr<listnode>CPUnode;						//this is the node running on the cpu
	shared_ptr<list> IO = make_shared<list>();			//this is the io queue
	shared_ptr<list> finished= make_shared<list>();		//this is the list of finished processes
	void CPU_time_quantom_14();							//time quantom 14
	void CPU_time_quantom_7();							//time quantom 7
	void CPU_fcfs();									//first come first serve
	void CPU_prempt();									//prempt the current CPU node
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