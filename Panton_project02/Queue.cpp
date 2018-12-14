#include "stdafx.h"
#include "Queue.h"


Queue::Queue()
{
	head = tail = nullptr;
	size = 0;
}


Queue::~Queue()
{
	clear();
}

int Queue::size()
{
	return size;
}

bool Queue::equal(Queue)
{

	return false;
}

void Queue::clear()
{
	while (head != nullptr)
	{
		node* doomed = head;
		head = head->next;
		delete doomed;
	}
	head = tail = nullptr;
	size = 0;
}

void Queue::enqueue(int value)
{
	if (size == 0)
	{
		head = tail = new node(value);
	}
	else
	{
		tail = tail->next = new node(value);
	}
	size++;
}

int Queue::dequeue()
{
	if (size == 0)
	{
		return -1;  // no item to return
	}
	
	node* doomed = head;
	int val = doomed->data;
	head = head->next;
	delete doomed;

	size--;

	return val;
}
