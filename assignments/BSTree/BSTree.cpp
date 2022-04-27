#include <iostream>
#include "BSTree.h"
#include "Node.h"
using namespace std;

BSTree::BSTree()
{
    root = nullptr;
}

void BSTree::insert(int d)
{

}

string BSTree::get_debug_string()
{
    return get_debug_stringL(root) + get_debug_stringR(root);
}

string BSTree::get_debug_stringL(Node *n)
{
    if(n == nullptr)
    {
        return "";
    }else{
        return to_string(n->getData()) + " --> " + get_debug_stringL(n->getLeft());
    }
}

string BSTree::get_debug_stringR(Node *n)
{
    if(n == nullptr)
    {
        return "";
    }else{
        return std::to_string(n->getData()) + " --> " +  get_debug_stringR(n->getRight());
    }
}

void BSTree::setup()
{
    Node *n = new Node(10);
    root = n;
    Node *n2 = new Node(20);
    root->setLeft(n2);
    Node *n3 = new Node(30);
    root->setRight(n3);
    Node *n4 = new Node(40);
    root->getLeft()->setLeft(n4);
}