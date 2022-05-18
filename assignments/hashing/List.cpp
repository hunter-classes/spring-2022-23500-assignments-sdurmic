#include <iostream>
#include "List.h"
#include <climits>
using namespace std;

List::List() 
{
    head = nullptr;
}

List::~List() 
{
    Node *n;
    while(head != nullptr) 
    {
        n = head;
        head = head->getNext();
        delete n;
    }
}

string List::toString() 
{
    Node *n = this->head;
    string str = "";
    while(n != nullptr) 
    {
        str += n->getPerson()->get_name() + "-->";
        n = n->getNext();
    }
    str += "nullptr";
    return str;
}

void List::insert(Person *d, int i) 
{
    Node *temp = new Node(d);
    Node *n1 = head;
    Node *n2 = nullptr;

    while(n1 != nullptr && i > 0) 
    {
        n2 = n1;
        n1 = n1->getNext();
        i = i - 1;
    }
    if(i > 0) 
    {
        throw out_of_range("Out of range");
        return;
    }
    if(n2 == nullptr) 
    {
        temp->setNext(head);
        head = temp;
    }else{
        temp->setNext(n1);
        n2->setNext(temp);
    }
}

void List::insert(Person *d) 
{
    Node *n = new Node(d);
    n->setNext(head);
    this->head = n;
}

void List::remove(int i) 
{
    Node *n1 = head;
    Node *n2 = nullptr;

    while(n1!=nullptr && i>0) 
    {
        n2 = n1;
        n1 = n1->getNext();
        i = i-1;
    }
    if(!n1) 
    {
        throw out_of_range("Out of range");
        return;
    }
    if(n2 == nullptr) 
    {
        head = n1->getNext();
        delete n1;
    }else{
        n2->setNext(n1->getNext());
        delete n1;
    }
}

Person* List::locate(Person *d, int i) 
{
    Node *n1 = head;
    while(n1!=nullptr && i>0) 
    {
        n1 = n1->getNext();
        i--;
    }
    if(n1) 
    {
        return n1->getPerson();
    }else{
        return nullptr;
    }
}

Node *List::getHead()
{
    return head;
}

Person* List::search(Person *d) 
{
    Node* n = head;
    while(n != nullptr) 
    {
        if(n->getPerson() == d) 
        {
           return n->getPerson();
        }
        n = n->getNext();
    }
    throw NOT_FOUND;
}