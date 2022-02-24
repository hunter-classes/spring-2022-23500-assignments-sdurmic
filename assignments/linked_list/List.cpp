#include <iostream>
#include "List.h"

List::List()
{
    head = nullptr;
}

//destructor
List::~List()
 {
   Node *n;
   for (n = head; head; n = head)
   {
     head = head->next
     delete n;
   }
}

void List::insert(string data)
{
    Node *newNode = new Node(data);

    newNode->setNext(head);
    head = newNode;
}

string List::toString()
{
    /*if(head == nullptr)
    {
        return "";
    }
    return head->getNext()->getData();
    */
    Node *walker = head;
    string s = "";
    while(walker != nullptr)
    {
        s = s + walker->getData() + "-->";
        walker = walker->getNext();
    }
    s = s + "nullptr";
    return s;
}

//locate
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

//delete
int List::remove(int n)
{
    Node *temp = head;
    if(n == 1)
    {
        head = temp->getNext();
        free(temp);
        return:
    }

    int x;
    for(x = 0; x < n-2; x++)
        temp = temp->getNext();
    Node *temp2 = temp->getNext();
    temp->getNext() = temp2->getNext();
    free(temp2);
}

};