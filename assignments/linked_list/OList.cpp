#include <iostream>
#include <stdexcept>
#include <string>
#include "OList.h"
#include "Node.h"
using namespace std;

OList::OList()
{
    head = nullptr;
}

OList::~OList()
{
    Node *n;
    cerr << "Destructing\n";
    while(head == nullptr)
    {
        n = head;
        head = head->getNext();
        delete n;
    }
}

void OList::insert(int val)
{
    Node *temp = new Node(val);
	Node *walker = head;
	Node *trailer = nullptr;
	
  	if(head == nullptr) 
    {
  		temp->setNext(head);
  		this->head = temp;
		return;
	}
	while(walker != nullptr && (val > walker->getData())) 
    {
		trailer = walker;
		walker = walker->getNext();
	}
	if(trailer == nullptr) 
    {
		temp->setNext(head);
        this->head = temp;
    }else{
		trailer->setNext(temp);
		temp->setNext(walker);
	}
}

int OList::remove(int n)
{
    Node *temp = head;
    Node *temp2 = nullptr;
    while(temp != nullptr && n > 0)
    {
        temp2 = temp;
        temp = temp->getNext();
        n = n-1;
    }
    if(temp == nullptr)
    {
        throw out_of_range("Out of range");
    }
    if(temp2 == nullptr)
    {
        head = temp2->getNext();
        delete temp;
    }else{
        temp2->setNext(temp->getNext());
        delete temp;
    }
    return 0;
}

int OList::get(int loc)
{
    Node *walker = head;

    while(walker && loc > 0)
    {
        walker = walker->getNext();
        loc--;
    }
    if(walker)
    {
        return walker->getData();
    }else{
        return -1;
    }
}

int OList::length()
{
    int l = 0;
    Node *walker = head;
    while (walker)
    {
        l++;
        walker = walker->getNext();
    }
    return l;
}

string OList::toString()
{
    string s = "head-->";
    Node *walker = this->head;
    while(walker != nullptr)
    {
        s = s + to_string(walker->getData()) + "-->";
        walker = walker->getNext();
    }
    s = s + "nullptr";
    return s;
}

int OList::locator(Node* head, int data)
{
	int i = 0;              
	Node *temp = head;
	while(temp != nullptr)
    {
		if(temp->data == data)         
			return i;               
		temp = temp->next;
		i++;
	}   
	return -1;                  
}

bool OList::contains(int val)
{
    if(val < head->getData()) //***
        return false;
    Node *walker = head;
    while(walker != nullptr)
    {
        if(walker->getData() == val) //***
            return true;
        if(walker->getData() > val) //***
        {
            return false;
        }
        walker = walker->getNext();
    }
    return false;
}

void OList::reverse()
{
    Node *walker = head;
    Node *trailer = nullptr;
    if(walker!=nullptr)
    {
        trailer = walker;
        walker = walker->getNext();
        while(walker!=nullptr)
        {
            trailer->setNext(walker->getNext());
            walker->setNext(head);
            head = walker;
            walker = trailer->getNext();
        }
    }
}