#include <iostream>
#include "Node.h"
#include "BSTree.h"
using namespace std;

BSTree::BSTree()
{
    root = nullptr;
}

string BSTree::traverse(Node *n)
{
    string a,b,c;
    if(n==nullptr)
    {
        return "";
    }else{
    a = traverse(n->getLeft());
    b = to_string(n->getData());
    c = traverse(n->getRight());

    return a + ", " + b+ ", " + c;
    }
};

string BSTree::get_debug_string()
{
    return traverse(root);
};

void BSTree::setup()
{
    Node *n = new Node(10);
    root = n;
    n = new Node(20);
    root->setRight(n);
    Node *n2 = new Node(30);
    n->setRight(n2);
    n2 = new Node(15);
    n->setLeft(n2);
    n2 = new Node(5);
    root->setLeft(n2);
    n = new Node(3);
    n2->setLeft(n);
    n = new Node(8);
    n2->setRight(n);
}

int BSTree::search(int value)
{
    Node *t = root;

    while (t != nullptr)
    {
        int tval = t->getData();
        if(tval==value)
        {
        return value;
        }
        if(tval < value)
        {
            t = t->getRight();
        }else{
            t = t->getLeft();
        }
    }

    throw 1;
}

void BSTree::insert(int value)
{
    Node *newnode = new Node(value);
    Node *p = root;
    Node *trailer;

    while(p != nullptr)
    {
        trailer = p;
        if(p->getData() == value)
        {
            return;
        }else if(p->getData() < value)
        {
            p = p->getRight(); 
        }else{
            p = p->getLeft();
        }
    }
    if(root==nullptr)
    {
        root=newnode;
    }else{
        if(trailer->getData() < value)
        {
            trailer->setRight(newnode);
        }else{
            trailer->setLeft(newnode);
        }
    }
}

int BSTree::rsearch(int value)
{
    return rsearch(value, n);
}

int BSTree::rsearch(int value, Node *p)
{
    if(p==nullptr)
    {
        throw TREE_ERR_VALUE_NOT_FOUND;
    }else if(p->getData()==value)
    {
        return value;
    }
    int val_p = p->getData();
    if(value>val_p)
    {
        return rsearch(value, p->getRight());
    }else{
        return rsearch(value, p->getLeft());
    }
}

void BSTree::rinsert(int value, Node *p)
{
  
}

void BSTree::rinsert(int value)
{
    
}