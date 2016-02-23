#ifndef QNODE_H
#define QNODE_H
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class qnode
{
public:
	qnode() :next(0) {};
	qnode(short unsigned p, vector<int>cpuB, vector<int>IOt) :next(0), priority(p), CPU_burst(cpuB), IO_time(IOt) {};
	~qnode(){	cout << "Deleted\n";	};
	vector<int> CPU_burst;
	vector<int> IO_time;
	short unsigned priority;

	shared_ptr<qnode> next; 
};

class queue
{
public:
	queue() :back(0), front(0) {};
	~queue() { };
	queue(const queue &) {};
	void Enqueue(int);
	void Dequeue() { front = front->next;  };
	void Print();

	friend ostream & operator<<(ostream & out, const queue & Org);

private:
	shared_ptr<qnode> back;
	shared_ptr<qnode> front;
};

typedef short unsigned type;
class stack_node {
public:
	type data;
	shared_ptr<stack_node> prev;
};


class stack {
public:
	stack() :top(0) {};
	stack(stack &) {};
	//stack(type);
	~stack() {};
	shared_ptr<stack_node>& getTop() { return top; };
	void push(const type &T);
	shared_ptr<stack_node>& pop();
	void print();
	void copy(const shared_ptr<stack_node>&);
	int length(const shared_ptr<stack_node>&);


	friend ostream & operator<<(ostream & out, const stack & Org);

private:
	void printHelper(const shared_ptr<stack_node>&);
	shared_ptr<stack_node> top;

};
#endif