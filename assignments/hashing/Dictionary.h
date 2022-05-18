#pragma once
#include "List.h"
using namespace std;

class Dictionary 
{
    private:
        List* listD[10];

    public:
        Dictionary(); 
        ~Dictionary(); 
        int hash(string name);
        void insertPerson(Person *d); 
        Person *retrievePerson(Person *d); 
        string getKeys();
};