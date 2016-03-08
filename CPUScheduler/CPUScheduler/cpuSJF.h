#ifndef SJF_H
#define SJF_H
#include "list.h"

class SJF
{
public:
	SJF() :CPUnode(0), counter(0) { queue = make_shared<list>(); };
	~SJF() {	};
	void start();


private:
	shared_ptr<list> queue;
	shared_ptr<listnode>CPUnode;
	//should be a list instead
	shared_ptr<list> IO = make_shared<list>();
	void CPU_SJF();
	void do_IO();
	void do_CPU();
	void init();
	void print();
	int counter;
};




#endif