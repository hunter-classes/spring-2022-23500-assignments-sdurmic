#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "stacks.h"
#include "Queue.h"
#include <iostream>
using namespace std;


TEST_CASE("Stack Functions:")
{
	Stack *s = new Stack();

	CHECK(s->is_empty() == true);

	s->push(5);
    CHECK(s->top() == 5);
    s->push(36);
    CHECK(s->top() == 36);
    s->push(22);
    CHECK(s->top() == 22);

	CHECK(s->is_empty() == false);

	s->pop();
    CHECK(s->top() == 36);
    s->pop();
    CHECK(s->top() == 5);
    s->pop();

	CHECK(s->is_empty() == true);

	CHECK_THROWS_AS(s->top(), out_of_range);
	CHECK_THROWS_AS(s->pop(), out_of_range);
	delete s;
}

TEST_CASE("Queue Functions")
{
	Queue *q = new Queue();

	CHECK_THROWS_AS(q->sequeue(), out_of_range);
	CHECK_THROWS_AS(q->front(), out_of_range);

	CHECK(q->is_empty());
    CHECK(!q->is_full());	
	
	q->enqueue(8);
	CHECK(q->front() == 8);

	q->enqueue(9);
	CHECK(q->front() == 8);

	for(int x=2; x<5; x++)
    {
		q->enqueue(x);
	}

	CHECK(q->front() == 8);

	CHECK_THROWS_AS(q->enqueue(55), out_of_range);

	CHECK(q->is_full());
	CHECK(!q->is_empty());

	delete q;
}