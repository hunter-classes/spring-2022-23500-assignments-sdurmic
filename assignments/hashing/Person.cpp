#include <iostream>
#include "Person.h"
using namespace std;

Person::Person(string first, string last, int num)
{
    this->first = first;
    this->last = last;
    this->idnum = num;
}

string Person::get_name()
{
    return last+", "+first;
}

int Person::get_id()
{
    return idnum;
}