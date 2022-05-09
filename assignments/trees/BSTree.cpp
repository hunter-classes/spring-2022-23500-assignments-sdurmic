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

int BSTree::rsearch(int val, Node *root)
{
    if(root==nullptr)
    {
        throw TREE_ERR_VALUE_NOT_FOUND;
    }else if(root->getData()==val)
    {
        return val;
    }
    int rootVal = root->getData();
    if(val>rootVal)
    {
        return rsearch(val, root->getRight());
    }else{
        return rsearch(val, root->getLeft());
    }
}

int BSTree::rsearch(int val)
{
    return rsearch(val, root);
}

void BSTree::insert(int value, Node *p)
{
    Node *newnode = new Node(value);
  
    //Node *p = root;
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
        if (trailer->getData() < value)
        {
            trailer->setRight(newnode);
        }else{
            trailer->setLeft(newnode);
        }
    }
}

void BSTree::deleteVal(int val) 
{
    Node *n = root;
    Node *trailer;

    while(n != nullptr) 
    {
        if(n->getData() == val) 
        {
            if((n->getRight() == nullptr)&&(n->getLeft() == nullptr)) 
            {
                if(trailer->getRight() == n) 
                {
                    trailer->setRight(nullptr);
                    return;
                }else{
                    trailer->setLeft(nullptr);
                return;
                }
            }
            if((n->getRight() != nullptr) && (n->getLeft() == nullptr)) 
            {
                if(trailer->getRight() == n) 
                {
                    trailer->setRight(n->getRight());
                    return;
                }else{
                    trailer->setLeft(n->getRight());
                    return;
                }
            }
            if((n->getRight() == nullptr) && (n->getLeft() != nullptr)) 
            {
                if(trailer->getRight() == n) 
                {
                    trailer->setRight(n->getLeft());
                    return;
                }else{
                    trailer->setLeft(n->getLeft());
                    return;
                }
            }
            if((n->getRight() != nullptr) && (n->getLeft() != nullptr)) 
            {
                Node *temp = n->getLeft();
                while(temp->getRight() != nullptr) 
                {
                    temp = temp->getRight();
                }
                int holder = temp->getData();
                this->deleteVal(holder);
                n->setData(holder);
            }
        }else if(n->getData() < val)
        {
            trailer = n;
            n = n->getRight();
        }else{
            trailer = n;
            n = n->getLeft();
        }
    }
    return;
}