OBJECTS=main.o BSTree.o Node.o 
TESTS=tests.o BSTree.o Node.o 
CXXFLAGS=
LDFLAGS=
CXX=g++

main: main.o BSTree.o Node.o 
		$(CXX) -o main $(OBJECTS) 

tests: tests.o BSTree.o Node.o
		$(CXX) -o tests $(TESTS)

main.o: main.cpp BSTree.h Node.h 

BSTree.o: BSTree.cpp BSTree.h Node.h

Node.o: Node.cpp Node.h

test.o: tests.cpp doctest.h BSTree.h Node.h 
		$(CXX) -c tests.cpp -std=c++11

clean:
		rm -f $(OBJECTS)