#include <iostream>
#include "Node.h"

Node::Node() 
{
    data = 0;
    left = NULL;
    right = NULL;
}

Node::Node(int data)
{
    this->data = data;
    left = NULL;
    right = NULL;
}

Node::Node(int data, Node *l, Node *r)
{
  this->data = data;
  left = l;
  right = r;
}

int Node::getData()
{
    return data;
}

Node * Node::getLeft()
{
    return left;
}

Node * Node::getRight()
{
    return right;
}

void Node::setData(int d)
{
    data = d;
}

void Node::setLeft(Node *l)
{
    left = l;
}

void Node::setRight(Node *r)
{
    right = r;
}