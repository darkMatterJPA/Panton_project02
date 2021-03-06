// Panton_project02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Queue.h"
# include <assert.h>
#include <iostream>

using namespace std;
int main()
{
	
	Queue q = Queue();

	q.enqueue(10);
	q.enqueue(30);
	q.enqueue(55);
	q.enqueue(60);

	cout << (q.dequeue() == 10);
		
	cout << (q.dequeue() == 30);

	cout << (q.size() > 0);

	Queue qi;

	cout << (qi.size() == 0);

	qi.enqueue(55);
	qi.enqueue(60);

	cout << (q.equal(qi));

	q.dequeue();

	cout << (!(q.equal(qi)));

    return 0;
}

