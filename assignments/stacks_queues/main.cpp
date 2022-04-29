#include <iostream>
#include <unistd.h>
#include "stacks.h"
#include "queue.h"
using namespace std;


int main()
{
    cout << "Stacks Functions:" << endl;
    Stack *s = new Stack();
    cout << s->is_empty() << endl;
    s->push(1);
    cout << s->top() << endl;
    cout << s->is_empty() << endl;
    s->push(2);
    cout << s->top() << endl;
    s->push(3);
    cout << s->top() << endl;

    cout << s->pop() << endl;
    cout << s->pop() << endl;
    cout << s->pop() << endl;

    cout << endl << "Queues Functions:" << endl;

    Queue *q = new Queue();

    cout << "Is empty? " << q->is_empty() << endl;
    cout << "Is full? " << q->is_full() << endl;
	
	q->enqueue(6);
	q->enqueue(7);
	q->enqueue(8);
	cout << "Queue: " << q->printQueue() << endl;

	cout << q->sequeue() << endl;
	cout << q->sequeue() << endl;
	cout << "Queue: " << q->printQueue() << endl;
	
	q->enqueue(20);
	q->enqueue(30);
	q->enqueue(40);
	cout << "Queue: " << q->printQueue() << endl;
	
	cout << q->sequeue() << endl;
	cout << "Queue: " << q->printQueue() << endl;
	
	return 0;
}
