#ifndef QNODE_H
#define QNODE_H
#include <iostream>
using namespace std;

class qnode
{
public:
	stack * CPU_burst;
	stack * IO_time;
	short unsigned priority;

	qnode *next;
};

class queue
{
public:
	queue() :back(0), front(0) {};
	~queue();
	queue(const queue &);
	void Enqueue(int);
	void Dequeue();
	void Print();

	friend ostream & operator<<(ostream & out, const queue & Org);

private:
	qnode *back;
	qnode *front;
};

typedef short unsigned type;
class stack_node {
public:
	type data;
	stack_node * prev;
};


class stack {
public:
	stack() :top(0) {};
	stack(stack &);
	stack(type);
	~stack();
	stack_node * getTop();
	void push(const type &);
	void pushPrefix(const type &);
	void pop();
	void print();
	void copy(const stack_node *);
	int length(const stack_node *);


	friend ostream & operator<<(ostream & out, const stack & Org);

private:
	void printHelper(const stack_node *);
	stack_node * top;

};
#endif