#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <memory>
#include <vector>
#include <thread>
#include <string>
using namespace std;

class listnode
{
public:
	listnode() :next(0), prev(0), priority(1), CPU_burst(0), IO_time(0), time_on(0), name(""), qu("Q1") {};
	listnode(short unsigned p, vector<int>cpuB, vector<int>IOt, string s, string q) :next(0), prev(0), priority(p), CPU_burst(cpuB), IO_time(IOt), time_on(0), name(s), qu(q) {};
	~listnode() { cout << "Deleted\n"; };
	vector<int> CPU_burst;
	vector<int> IO_time;
	short unsigned priority;
	short unsigned time_on;
	shared_ptr<listnode> next;
	shared_ptr<listnode> prev;
	string name, qu;
};

class list
{
public:
	list() :front(0) {};
	~list() { };
	list(const list &) {};
	void insert(shared_ptr<listnode>&);
	shared_ptr<listnode> remove_front();
	void remove_node(shared_ptr<listnode>&);
	//void Print();
	shared_ptr<listnode>& get_front() { return front; };

	bool empty();
	friend ostream & operator<<(ostream & out, shared_ptr<list> & Org);
	 
private:
	shared_ptr<listnode> front;
};

#endif