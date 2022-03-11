#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 
#include "doctest.h"
#include "OList.h"

TEST_CASE("Insert Test:") 
{
	OList *l = new OList();
    l->insert(3);
    l->insert(6);
    l->insert(9);	
	l->insert(12);
	CHECK(l->toString() == "head-->3-->6-->9-->12-->nullptr");
}

TEST_CASE("Contains Test:")
{
	OList *l = new OList();
	CHECK(l->contains(3) == false);
	l->insert(3);
	CHECK(l->contains(3) == true);
}

TEST_CASE("Get Test:")
{
	OList *l = new OList();
    l->insert(4);
    l->insert(8);
    l->insert(12);
	CHECK(l->get(0) == 4);
	CHECK(l->get(1) == 8);
	CHECK(l->get(2) == 12);
}

TEST_CASE("Remove Test:")
{
	OList *l = new OList();
    l->insert(11);
    l->insert(52);
    l->insert(4);
    l->insert(33);
    l->insert(100);
	CHECK(l->toString() == "head-->11-->52-->4-->33-->100-->nullptr");
	l->remove(3);
	CHECK(l->toString() == "head-->11-->52-->4-->100-->nullptr");
}

TEST_CASE("Reverse Test:")
{
	OList *l = new OList();
    l->insert(11);
    l->insert(52);
    l->insert(4);
    l->insert(33);
    l->insert(100);
	CHECK(l->toString() == "head-->100-->33-->4-->52-->11-->nullptr");
}