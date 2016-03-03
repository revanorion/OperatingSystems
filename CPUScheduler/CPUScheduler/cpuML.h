#ifndef ML_H
#define ML_H
#include "list.h"

class ML
{
public:
	ML() :CPUnode(0), counter(0) { queue = make_shared<list>();};
	~ML() {	};
	void start();


private:
	shared_ptr<list> queue;
	shared_ptr<listnode>CPUnode;
	//should be a list instead
	shared_ptr<list> IO = make_shared<list>();
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