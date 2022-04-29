main: main.o stacks.o List.o Node.o Queue.o
	g++ -o main main.o stacks.o List.o Node.o Queue.o

tests: tests.o stacks.o List.o Node.o Queue.o
	g++ -o tests tests.o stacks.o List.o Node.o Queue.o

tests.o: tests.cpp doctest.h
	g++ -c tests.cpp

main.o: main.cpp stacks.h
	g++ -c main.cpp

stack.o: stacks.cpp stacks.h
	g++ -c stacks.cpp

queue.o: Queue.cpp Queue.h
	g++ -c Queue.cpp

List.o: List.cpp List.h
	g++ -c List.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

clean:
	rm -f *.o