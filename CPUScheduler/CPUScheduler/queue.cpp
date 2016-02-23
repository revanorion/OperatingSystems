#include "queue.h"

void queue::Enqueue(int x)
{
	//shared_ptr<qnode> newNode = make_shared(x);
}

void queue::Print()
{
}

ostream & operator<<(ostream & out, const queue & Org)
{
	// TODO: insert return statement here
}

ostream & operator<<(ostream & out, const stack & Org)
{
	// TODO: insert return statement here
}

void stack::push(const type & T)
{
}

shared_ptr<stack_node>& stack::pop()
{
	// TODO: insert return statement here
}

void stack::print()
{
}

void stack::copy(const shared_ptr<stack_node>&)
{
}

int stack::length(const shared_ptr<stack_node>&)
{
	return 0;
}

void stack::printHelper(const shared_ptr<stack_node>&)
{
}
