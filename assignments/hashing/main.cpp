#include <iostream>
#include "Dictionary.h"
using namespace std;

int main() 
{
    Dictionary *D = new Dictionary();
    Person *first = new Person("Durmic", "Sara", 1);
    Person *second = new Person("Khan", "Zaeem", 2);
    Person *third = new Person("Abida", "Nuzhat", 3);
    Person *fourth = new Person("Smith", "Jane", 4);
  
    D->insertPerson(first);
    D->insertPerson(second);
    D->insertPerson(third);
    cout << "Dictionary with 3 people: " << D->getKeys() << endl;
    D->insertPerson(fourth);
    cout << "Dictionary with 4 people: " << D->getKeys() << endl;

    cout << "Retrieve first person: " << endl;
    cout << D->retrievePerson(first) << endl;

    cout << "Destructor" << endl;
    D->~Dictionary();

    return 0;
}
