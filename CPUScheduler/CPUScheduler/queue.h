#ifndef QNODE_H
#define QNODE_H
#include <iostream>
#include <memory>
#include <vector>
#include <thread>
using namespace std;

class qnode
{
public:
	qnode() :next(0), priority(0), CPU_burst(0), IO_time(0), time_on(0) {};
	qnode(short unsigned p, vector<int>cpuB, vector<int>IOt) :next(0), priority(p), CPU_burst(cpuB), IO_time(IOt), time_on(0) {};
	~qnode(){	cout << "Deleted\n";	};
	vector<int> CPU_burst;
	vector<int> IO_time;
	short unsigned priority;
	short unsigned time_on;
	shared_ptr<qnode> next; 
};

class queue
{
public:
	queue() :back(0), front(0) {};
	~queue() { };
	queue(const queue &) {};
	void Enqueue(int);
	void Enqueue(shared_ptr<qnode>&);
	shared_ptr<qnode>& Dequeue();
	void remove_node(shared_ptr<qnode>&);
	void Print();
	shared_ptr<qnode>& get_front() { return front; };
	shared_ptr<qnode>& get_back() { return back; };
	bool empty();
	friend ostream & operator<<(ostream & out, const queue & Org);

private:
	shared_ptr<qnode> back;
	shared_ptr<qnode> front;
};

#endif