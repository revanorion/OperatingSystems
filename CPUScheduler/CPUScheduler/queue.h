#ifndef QNODE_H
#define QNODE_H
#include <iostream>
#include <memory>
#include <vector>
#include <thread>
#include <string>
using namespace std;

class qnode
{
public:
	qnode() :next(0), priority(1), CPU_burst(0), IO_time(0), time_on(0), name(""),qu("Q1") {};
	qnode(short unsigned p, vector<int>cpuB, vector<int>IOt, string s, string q) :next(0), priority(p), CPU_burst(cpuB), IO_time(IOt), time_on(0), name(s), qu(q) {};
	~qnode(){	cout << "Deleted\n";	};
	vector<int> CPU_burst;
	vector<int> IO_time;
	short unsigned priority;
	short unsigned time_on;
	shared_ptr<qnode> next; 
	string name,qu;
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
	friend ostream & operator<<(ostream & out, shared_ptr<queue> & Org);

private:
	shared_ptr<qnode> back;
	shared_ptr<qnode> front;
};

#endif