#include "list.h"
//insert processes nodes in the order of queue priority
void list::insert(shared_ptr<listnode>& x)
{
	if (front == 0)
	{
		front = x;
	}
	else if (front->qu > x->qu)
	{
		x->next = front;
		front->prev = x;
		front = x;
	}
	else
	{
		shared_ptr<listnode> n = front;
		bool insertd = false;
		while (n != 0 && !insertd)
		{
			if (n->qu > x->qu)
			{
				x->next = n;
				x->prev = n->prev;
				n->prev->next = x;
				n->prev = x;
				insertd = true;
			}
			else if (n->next == 0)
			{
				x->prev = n;
				n->next = x;
				insertd = true;
			}
			else
				n = n->next;
		}

	}
}

//insert inorder based on shortest cpu burst
void list::insertInorder(shared_ptr<listnode>& x)
{
	if (front == 0)
	{
		front = x;
	}
	else if (front->CPU_burst.back() > x->CPU_burst.back())
	{
		x->next = front;
		front->prev = x;
		front = x;
	}
	else
	{
		shared_ptr<listnode> n = front;
		bool insertd = false;
		while (n != 0 && !insertd)
		{
			if (n->CPU_burst.back() > x->CPU_burst.back())
			{
				x->next = n;
				x->prev = n->prev;
				n->prev->next = x;
				n->prev = x;
				insertd = true;
			}
			else if (n->next == 0)
			{
				x->prev = n;
				n->next = x;
				insertd = true;
			}
			else
				n = n->next;
		}

	}
}

//remove the front process from list and return it
shared_ptr<listnode> list::remove_front()
{
	shared_ptr<listnode> x = front;

	if (front->next == 0)
	{
		front = 0;
	}
	else
	{
		front->next->prev = 0;
		front = front->next;
	}
	x->next = 0;
	x->prev = 0;
	return x;

}

//remove any process x from the list
void list::remove_node(shared_ptr<listnode>&x)
{

	if (x == front)
	{
	if (front->next != 0)
		front->next->prev = 0;
		front = front->next;
		x->next = 0;
	}
	else {
		x->prev->next = x->next;
		if(x->next!=0)
			x->next->prev = x->prev;
		x->next = x->prev = 0;
	}
}

bool list::empty()
{
	return (front == 0) ? true : false;
}

//calculate the average of the waiting time, response time, and the turnaround time for all the processes
void list::calcAvg()
{
	int sum1, sum2, sum3, items;
	sum1 = sum2 = sum3 = items = 0;
	shared_ptr<listnode> node = front;
	while (node != 0)
	{
		node->calcAvg();
		sum1 += node->aRT;
		sum2 += node->aWT;
		sum3 += node->aTT;
		items++;
		node = node->next;
	}
	aRT = sum1 / items;
	aWT = sum2 / items;
	aTT = sum3 / items;
}

//print list
ostream & operator<<(ostream & out, shared_ptr<list> & Org)
{
	shared_ptr<listnode> newNode = Org->get_front();
	if (newNode == 0)
		out << "\t\t[empty]\n";
	else
		while (newNode != 0)
		{
			if(!newNode->IO_time.empty())
				out << "\t\t" << newNode->name << "\t\t" << newNode->IO_time.back() << endl;
			newNode = newNode->next;
		}
	return out;
}

//calculate the average of the waiting time, response time, and the turnaround time for the process
void listnode::calcAvg()
{
	int sum=0;
	for (int x = 0; x < waiting_time.size(); x++)
		sum += waiting_time[x];
	aWT = sum / waiting_time.size();
	sum = 0;
	for (int x = 0; x < turnaround_time.size(); x++)
		sum += turnaround_time[x];
	aTT = sum / turnaround_time.size();
	sum = 0;
	for (int x = 0; x < response_time.size(); x++)
		sum += response_time[x];
	aRT = sum / response_time.size();
	sum = 0;
}
