#include <iostream>
#include "Node.h"


Node::Node() : next(nullptr)
{

}

Node::Node(string data)
{
    this->data = data;
    this->next = nullptr;
}

Node::Node(string data, Node *next)
{
    this->data = data;
    this->next = next;
}

void Node::setData(string data)
{
    this->data = data;
}

void Node::setNext(Node *next)
{
    this->next = next;
}

string Node::getData()
{
    return this->data;
}

Node *Node::getNext()
{
    return this->next;
}
