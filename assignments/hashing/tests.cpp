#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Node.h"
#include "Dictionary.h"
#include "List.h"
#include "Person.h"
using namespace std;

TEST_CASE("Tests for hash functions")
{
	Dictionary *dict = new Dictionary();
	Person *one = new Person("Durmic", "Sara", 1);
  	dict->insertPerson(one);
  	CHECK(dict->retrievePerson(one)->get_name() == "Sara, Durmic");
  	Person *two = new Person("Khan", "Zaeem", 2);
	dict->insertPerson(two);
    CHECK(dict->retrievePerson(two)->get_name() == "Zaeem, Khan");
    Person *three = new Person("Abida", "Nuzhat", 3);
	dict->insertPerson(three);
	CHECK(dict->retrievePerson(three)->get_name() == "Nuzhat, Abida");
	Person *four = new Person("Smith", "Jane", 4);
	dict->insertPerson(four);
	CHECK(dict->retrievePerson(four)->get_name() == "Jane, Smith");
	
	CHECK(dict->getKeys() == "Zaeem, Khan-->nullptr, Jane, Smith-->Nuzhat, Abida-->nullptr, Sara, Durmic-->nullptr, ");

	delete dict;
}