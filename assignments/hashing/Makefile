OBJECTS=main.o Dictionary.o List.o Node.o Person.o
TESTS=tests.o Dictionary.o List.o Node.o Person.o
CXXFLAGS=
LDFLAGS=
CXX=g++

main: main.o Dictionary.o List.o Node.o Person.o
		$(CXX) -o main $(OBJECTS) 

tests: tests.o Dictionary.o List.o Node.o Person.o
		$(CXX) -o tests $(TESTS)

main.o: main.cpp Dictionary.h List.h Node.h Person.h

Dictionary.o: Dictionary.cpp Dictionary.h

Node.o: Node.cpp Node.h

List.o: List.cpp List.h

Person.o: Person.cpp Person.h

test.o: tests.cpp doctest.h Dictionary.h List.h Node.h Person.h
		$(CXX) -c tests.cpp -std=c++11

clean:
		rm -f $(OBJECTS)