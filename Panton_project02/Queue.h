#pragma once
class node
{
	//Private function and Member variables for node class 
private:
	int data;
	node* next;
	friend class Queue;  //Friend to the Queue class

						  //constructor for node
	node(int value, node* nxt = nullptr)
	{
		data = value;
		next = nxt;
	}


};


class Queue
{
	/**
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;; ADT Queue algebraic specs
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;;
	;; CANONICAL CONSTRUCTORS
	;; queue() : -> Queue
	;; enqueue() : Queue , X -> Queue
	;;
	;; OBSERVERS
	;; enqueue() : Queue -> Queue
	;; dequeue() : Queue -> Queue
	;; size() : Queue -> Natural
	;; equal() : Queue, Queue -> Boolean
	;; clear() : Queue -> Queue



	*/

private:
	node * head;    //start of the Queue
	node* tail;   // end of the Queue
	int size;
public:
	Queue();
	virtual ~Queue();
	int size();
	bool equal(Queue);
	void clear();
	void enqueue(int);
	int dequeue();
};

