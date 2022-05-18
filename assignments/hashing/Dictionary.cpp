#include <iostream>
#include "Dictionary.h"
using namespace std;

Dictionary::Dictionary()
{
    for(int i=0; i<10; i++)
    {
        listD[i] = new List();
    }
}

Dictionary::~Dictionary()
{
    for(int i=0; i<10; i++)
    {
        listD[i]->~List();
    }
}

int Dictionary::hash(string name)
{
    int x = 0;
    for (int i=0; i<name.length(); i++)
    {
        x = x + int(name[i]);
    }
    return x%10;
}

void Dictionary::insertPerson(Person *d)
{
    string name = d->get_name();
    int i = hash(name);
    listD[i]->insert(d);
}

Person *Dictionary::retrievePerson(Person *d)
{
    int i = hash(d->get_name());
    if(listD[i] == nullptr) 
    {
        throw NOT_FOUND;
    }
    return listD[i]->search(d);
}

string Dictionary::getKeys()
{
    string str = "";
    for(int i=0; i<10; i++)
    {
        if(listD[i]->toString() != "nullptr")
        {
            str = str + listD[i]->toString() + ", ";
        }
    }
    return str;
}