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
	listnode() :next(0), prev(0), priority(1), CPU_burst(0), IO_time(0), time_on(0), name(""),first_response(true), qu("Q1") {};
	listnode(short unsigned p, vector<int>cpuB, vector<int>IOt, string s, string q) :next(0), prev(0), priority(p), CPU_burst(cpuB), IO_time(IOt), time_on(0), name(s), qu(q) {};
	~listnode() { cout << "\nProcess "<<name<<" Deleted\n"; };
	vector<int> CPU_burst;			//vector containing all the burst times
	vector<int> waiting_time;		//vector containing wait time for each burst
	vector<int> turnaround_time;	//vector containing turnaround time for each burst
	vector<int> response_time;		//vector containing response time for each burst
	vector<int> IO_time;			//vector containing the io for each burst
	short unsigned priority;		//priority for the process
	short unsigned time_on;			//how long the process spent on the processor
	shared_ptr<listnode> next;		//next item in the list
	shared_ptr<listnode> prev;		//previous item in the list
	string name, qu;				//name of the process and the queue process is in
	bool first_response;			//used to document the response time
	double aRT, aWT, aTT;			//holds the average values
	void calcAvg();					//calculate the average of the waiting time, response time, and the turnaround time for the process
};

class list
{
public:
	list() :front(0) {};
	~list() { };
	list(const list &) {};
	void insert(shared_ptr<listnode>&);
	void insertInorder(shared_ptr<listnode>&);
	shared_ptr<listnode> remove_front();
	void remove_node(shared_ptr<listnode>&);
	shared_ptr<listnode>& get_front() { return front; };
	bool empty();					//If list is empty
	friend ostream & operator<<(ostream & out, shared_ptr<list> & Org);
	double aRT, aWT, aTT;			//holds the average values
	void calcAvg();					//calculate the average of the waiting time, response time, and the turnaround time for all the processes
private:
	shared_ptr<listnode> front;
};

#endif