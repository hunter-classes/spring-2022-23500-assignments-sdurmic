#include <iostream>
#include "Queue.h"
using namespace std;


Queue::Queue()
{
	start = 0;
    end = 0;
	full = false;
}

void Queue::enqueue(int item)
{
	if(end-start==5 || start-end==5)
	{
		full = true;
		throw out_of_range("queue is full");
	}
	arr[end%5] = item;
	end++;
}

int Queue::sequeue()
{
	if(start==end)
	{
		throw out_of_range("queue is empty");
	}
	int i = front();
	start++;
	full = false;
	return i;
}

int Queue::front()
{
	if(start==end)
	{
		throw out_of_range("queue is empty");
	}
	return arr[start%5];
}

bool Queue::is_empty()
{
	return !full;
}

bool Queue::is_full()
{
	return full;
}

string Queue::printQueue()
{
	string s = "";
	for(int x=start; x<end; x++)
	{
		s += to_string(arr[x%5])+" ";
	}
	return s;
}