a.exe: Money.o main.o
	g++ Money.o main.o

Money.o: Money.h Money.cpp
	g++ -c -g Money.cpp

main.o: Money.h main.cpp
	g++ -c -g main.cpp

clean:
	delete *.o a.exe