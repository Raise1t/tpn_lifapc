CC = g++
FLAGS = -Wall

main : main.o librairie.o sommet.o terrain.o
	$(CC) -o $@ $^

main.o : main.cpp
	$(CC) -c $^ $(FLAGS)

librairie.o : librairie.h librairie.cpp
	$(CC) -c $^ $(FLAGS)

sommet.o : sommet.h sommet.cpp
	$(CC) -c $^ $(FLAGS)

terrain.o : terrain.h terrain.cpp
	$(CC) -c $^ $(FLAGS)