#pragma once
#include <iostream>
using namespace std;

class Person
{
    private:
        string first; 
        string last; 
        int idnum; 

    public:
        Person(string first, string last, int num);
        string get_name();
        int get_id();
};