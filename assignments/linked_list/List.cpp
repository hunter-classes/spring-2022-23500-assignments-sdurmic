#include <iostream>
#include "List.h"
using namespace std;

List::List()
{
    head = nullptr;
}

List::~List()
 {
    Node *n;
    cerr << "Destructing\n";
    while(head = nullptr)
    {
        n = head;
        head = head->getNext();
        delete n;
    }
}

void List::insert(string data)
{
    Node *newNode = new Node(data);
    newNode->setNext(head);
    this->head = newNode;
}

void List::insert(int loc, string data)
{
    Node *tmp = new Node(data);
    Node *walker = head;
    Node *trailer = nullptr;
  
    while (walker != nullptr && loc > 0)
    {
        trailer = walker;
        walker = walker->getNext();
        loc = loc - 1;
    }

    if (loc > 0)
    {
        throw out_of_range("Out of range");
    }

    if (trailer==nullptr)
    {
        tmp->setNext(head);
        head = tmp;
    }else{
    tmp->setNext(walker);
    trailer->setNext(tmp);
    }
}

int List::remove(int n)
{
    Node *temp = head;
    Node *temp2 = nullptr;
    while(temp != nullptr && n > 0)
    {
        temp2 = temp;
        temp = temp->getNext();
        n = n-1;
    }
    if(temp = nullptr)
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
}

string List::get(int loc)
{
    string result = "";
    Node *walker = head;

    while(walker && loc > 0)
    {
        walker = walker->getNext();
        loc--;
    }
    if(walker)
        return walker->getData();
    else
        return "";   
}

int List::length()
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

string List::toString()
{
    Node *walker = this->head;
    string s = "";
    while(walker != nullptr)
    {
        s = s + walker->getData() + "-->";
        walker = walker->getNext();
    }
    s = s + "null";
    return s;
}

int List::locator(Node* head, string data)
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

};