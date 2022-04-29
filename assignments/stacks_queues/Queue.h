#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

#define QUEUE_ERR_EMPTY 1
#define QUEUE_ERR_FULL 2
#define QUEUE_ERR_OTHER 4

class Queue
{
	private:
		int start, end;
		bool full;
        int arr[5];

	public:
		Queue();
		void enqueue(int x);
		int sequeue();
		int front();
		bool is_empty();
		bool is_full();
		string printQueue();
};