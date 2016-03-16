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

void list::insertInorderName(shared_ptr<listnode>& x)
{
	if (front == 0)
	{
		front = x;
	}
	else if (front->name > x->name)
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
			if (n->name > x->name)
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

void list::insertBack(shared_ptr<listnode>& x)
{
	if (front == 0)
	{
		front = x;
	}
	else
	{
		shared_ptr<listnode> n = front;
		bool insertd = false;
		while (n != 0 && !insertd)
		{
			if (n->next == 0)
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
		if (x->next != 0)
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
		sum1 += node->response_time;
		sum2 += node->waiting_time;
		sum3 += node->turnaround_time;
		items++;
		node = node->next;
	}
	aRT = sum1 / items;
	aWT = sum2 / items;
	aTT = sum3 / items;
	printTimes();
}

void list::printTimes()
{
	shared_ptr<listnode> node = front;
	while (node != 0)
	{
		cout << node->name << "\t" << node->waiting_time << "\t" << node->turnaround_time << "\t" << node->response_time << endl;
		node = node->next;
	}
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
			if (!newNode->IO_time.empty())
				out << "\t\t" << newNode->name << "\t\t" << newNode->IO_time.back() << endl;
			newNode = newNode->next;
		}
	return out;
}

