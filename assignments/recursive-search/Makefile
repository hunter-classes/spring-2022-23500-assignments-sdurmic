main: main.o Knight.o
	g++ -o main main.o Knight.o

main.o: main.cpp Knight.h
	g++ -c main.cpp

Knight.o: Knight.cpp
	g++ -c Knight.cpp
	
clean:
	rm -f *.o