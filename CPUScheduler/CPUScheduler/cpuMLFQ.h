#ifndef MLFQ_H
#define MLFQ_H
#include "queue.h"

class MLFQ
{
public:
	MLFQ() :CPUnode(0), counter(0) { queue1 = make_shared<queue>(); queue2 = make_shared<queue>(); fcfs = make_shared<queue>(); };
	~MLFQ() {	};
	void start();


private:
	shared_ptr<queue> queue1;
	shared_ptr<queue> queue2;
	shared_ptr<queue> fcfs;
	shared_ptr<qnode>CPUnode;
	//should be a list instead
	shared_ptr<queue> IO = make_shared<queue>();
	void CPU_time_quantom_14();
	void CPU_time_quantom_7();
	void CPU_fcfs();
	void CPU_prempt();
	void do_IO();
	void do_CPU();
	void init();
	void print();
	int counter;
};




#endif