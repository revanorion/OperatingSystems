#include "queue.h"

void queue::Enqueue(int x)
{
	if (front == 0)
	{
		shared_ptr<qnode> newNode = make_shared<qnode>();
		newNode->priority = x;
		front = back = newNode;
		front->next = back;
	}
	//else if(front==back)
	//{
	//	shared_ptr<qnode> newNode = make_shared<qnode>();
	//	newNode->priority = x;
	//	back = newNode;
	//	front->next = back;
	//}
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
		front = back =node;
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

ostream & operator<<(ostream & out, const queue & Org)
{
	// TODO: insert return statement here
	return out;
}
