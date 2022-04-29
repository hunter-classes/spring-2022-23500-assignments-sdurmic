#include <iostream>
#include <climits>
#include "List.h"
using namespace std;

List::List() 
{
    head = nullptr;
}

List::~List() 
{
    Node *trailer;
    while(head != nullptr) 
    {
        trailer=head;
        head=head->getNext();
        delete trailer;
    }
}

void List::insert(int data) 
{
    Node *temp = new Node(data);
    temp->setNext(head);
    this->head = temp;
}

string List::toString() 
{
    Node *walker = head;
    string res  = "";
    while(walker != nullptr) 
    {
        res += to_string(walker->getData()) + "-->";
        walker = walker->getNext();
    }
    res += "nullptr";
    return res;
}

int List::locate(int i) 
{
    string res = "";
    Node *walker = head;

    while(walker!=nullptr && i>0) 
    {
        walker = walker->getNext();
        i--;
    }
    if(walker) 
    {
        return walker->getData();
    }else{
        return INT_MIN;
    }
}

void List::remove(int i) 
{
    Node *walker = head;
    Node *trailer = nullptr;

    while(walker!=nullptr && i>0) 
    {
        trailer = walker;
        walker = walker->getNext();
        i -= 1;
    }
    if(!walker) 
    {
        throw out_of_range("Out of range");
        return;
    }
    if(trailer==nullptr) 
    {
        head = walker->getNext();
        delete walker;
    }else{
        trailer->setNext(walker->getNext());
        delete walker;
    }
}
