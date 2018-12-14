#pragma once

//template<class T>
class node
{
	//Private function and Member variables for node class 
private:
	//template<typename T>
	 int data;
	node* next;
	friend class Queue;  //Friend to the Queue class

	//template<typename T>					  //constructor for node
	node(int value, node* nxt = nullptr)
	{
		data = value;
		next = nxt;
	}


};


//template<class T>
class Queue
{
	/**
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;; ADT Queue algebraic specs
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;;
	;; CANONICAL CONSTRUCTORS
	;; queue() : -> Queue
	;; enqueue() : X -> Queue
	;;
	;; OBSERVERS
	;; enqueue() : X -> Queue
	;; dequeue() : Queue -> Queue
	;; size() : Queue -> Natural
	;; equal() : Queue -> Boolean
	;; clear() : Queue -> Queue




	;; CONSTRUCTOR AXIOMS
	;;
	;; ;;;;; The following Axiom specifies "Queue" constructor semantics ;;;;;;
	;; Queue() -> Queue
	;; AXIOM: 
	;; Queue() - therefore -
	;; size() = 0
	;;
	;; ;;;;; The following Axiom specifies "enqueue" constructor semantics ;;;;;;
	;; enqueue() : X -> Queue
	;;
	;; AXIOM: For all Q in Queue and X
	;; enqueue(X)  - therefore -
	;; size() > 0
	;;
	;; AXIOM: For all Q in Queue
	;; enqueue(X) - then -
	;; enqueue(Xi) - then - 
	;; dequeue() -> Q             ;; enqueue() can be undone via dequeue()
	;;
	;; AXIOM: For all Q in Queue
	;; enqueue(X) - then -
	;; equal(Q) -> False    ;; enqueue() modifies the Queue
	;;
	;; AXIOM: For all Q in Queue
	;; enqueue(X) - then -
	;; dequeue() -> X             ;; item enqueued is always at the tail of Queue
	;;
	;; AXIOM: For all Q in Queue
	;; enqueue(X) - then -
	;; enqueue(X1) - then -
	;; dequeue() -> X   ;; order matters

	;;
	;; OBSERVER AXIOMS
	;;
	;; dequeue:
	;; AXIOM:
	;; queue() - then -
	;; dequeue() -> ERROR
	;;    - also -
	;; AXIOM: For all Q in Queue
	;; dequeue(enqueue(Q, X)) -> X
	;;
	;; size:
	;; AXIOM: size(queue()) -> 0
	;;    - also -
	;; AXIOM: For all Q in Queue
	;; size(enqueue(Q, X)) -> 1 + size(Q)
	;;
	;; equal:
	;; AXIOM: For all Q in Queue
	;; equal(enqueue(Q, X), Q) -> False     ;; enqueue() produces a different Queue
	;;    - also -
	;; AXIOM: For all Q, Q1 in Queue and X, X1  ;; Specifies criteria for equality
	;; equal(enqueue(Q, X), enqueue(Q1, X1)) ->
	;;     True if equal(Q, Q1) and X is equal X1
	;;     else False
	;;    - also -
	;; AXIOM: For all Q, Q1 in Queue
	;; equal(Q, Q1) -> equal(Q1, Q)       ;; Order of comparison doesn't matter
	;;    - also -
	;; AXIOM: For all Q in Queue          ;; Identity property of equal()
	;; equal(Q, Q) -> True
	;;
	;; clear:
	;; AXIOM: For all Q in Queue
	;; clear(enqueue(Q, X)) -> queue()
	;;         - also -
	;; clear(queue()) -> queue()


	*/

private:
	node * head;    //start of the Queue
	node* tail;   // end of the Queue
	int Qsize;
public:
	/*
	 CONTRACT: queue() : -> Queue
	*/
	Queue()
	{
		head = tail = nullptr;
		Qsize = 0;
	}

	/**/
	virtual ~Queue()
	{
		clear();
	}

	/*
	
	*/
	int size()
	{
		return Qsize;
	}

	/*
	
	*/
	//template<typename T>
	bool equal(Queue comp)
	{
		if (this->Qsize == comp.Qsize && this->head->data == comp.head->data && this->tail->data == comp.tail->data)
			return true;
		else
			return false;
	}

	/*
	
	*/
	void clear()
	{
		while (head != nullptr)
		{
			node* doomed = head;
			head = head->next;
			delete doomed;
		}
		head = tail = nullptr;
		Qsize = 0;
	}

	/*
	 CONTRACT: enqueue(X) -> Queue
	 For all Q in Queue
	 enqueue(X) -> Queue
	*/
	//template<typename T>
	void enqueue(int value)
	{
		if (Qsize == 0)
		{
			head = tail = new node(value);
		}
		else
		{
			tail = tail->next = new node(value);
		}
		Qsize++;
	}

	/*
	
	*/
	//template<typename T>
	int dequeue()
	{
		if (Qsize == 0)
		{
			return -1;  // no item to return
		}

		node* doomed = head;
		int val = doomed->data;
		head = head->next;
		delete doomed;

		Qsize--;

		return val;
	}
};

