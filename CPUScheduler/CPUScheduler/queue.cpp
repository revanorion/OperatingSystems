#include "queue.h"

void queue::Enqueue(int x)
{
	if (front == 0)
	{
		shared_ptr<qnode> newNode = make_shared<qnode>();
		newNode->priority = x;
		front = newNode;

	}
	else if (back == 0) {
		shared_ptr<qnode> newNode = make_shared<qnode>();
		newNode->priority = x;
		front->next = back;
		back = newNode;
	}
	else
	{
		shared_ptr<qnode> newNode = make_shared<qnode>();
		newNode->priority = x;
		back->next = newNode;
		back = newNode;
	}

}

void queue::Enqueue(shared_ptr<qnode>& node)
{
	if (front == 0)
	{
		front = node;

	}
	else if (back == 0)
	{
		back = node;
		front->next = back;
	}
	else
	{
		back->next = node;
		back = node;
	}
}

shared_ptr<qnode>& queue::Dequeue()
{
	shared_ptr<qnode> newNode = front;
	front = front->next;
	newNode->next = 0;
	return newNode;
}

void queue::remove_node(shared_ptr<qnode>& remove)
{
	shared_ptr<qnode> nodeParent = front;
	shared_ptr<qnode> node = front;
	shared_ptr<qnode> nodeNext = 0;
	while (node != 0)
	{
		nodeNext = node->next;
		if (front == remove)
		{
			front = front->next;
			return;
		}
		if (node == remove)
		{
			nodeParent->next = nodeNext;
			node->next = 0;
			return;
		}
		nodeParent = node;
		node = nodeNext;
	}

}

void queue::Print()
{
	shared_ptr<qnode> newNode = front;
	while (newNode != 0)
	{
		cout << newNode->priority << endl;
		newNode = newNode->next;
	}
}

bool queue::empty()
{
	if (front == 0)
		return true;
	else
		return false;
}

ostream & operator<<(ostream & out, shared_ptr<queue> & Org)
{
	shared_ptr<qnode> newNode = Org->get_front();
	if (newNode == 0)
		out << "\t\t[empty]\n";
	else
		while (newNode != 0)
		{
			out<<"\t\t" << newNode->name << "\t\t" << newNode->IO_time.back() << endl;
			newNode = newNode->next;
		}
	return out;
}
