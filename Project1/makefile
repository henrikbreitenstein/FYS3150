
#BUILDER FOR: main.cpp
all: compile link run

compile:
	g++ -c main.cpp -o main.o

link:
	g++ main.o -o main.out

run:
	./main.out

#BUILDER FOR: solve.cpp
solveall: csolve slink srun

csolve:
	g++ -c solve.cpp -o solve.o

slink:
	g++ solve.o -o solve.out -larmadillo

srun:
	./solve.out

#BUILDER FOR: problem9.cpp

p9all: p9comp p9link p9run

p9comp:
	g++ -c problem9.cpp problem9func.cpp

p9link:
	g++ problem9.o problem9func.o -o p9.out

p9run:
	./p9.out

#BUILDER FOR: Project73.cpp

clr73: comp73 link73 run73

comp73:
	g++ -c project73.cpp project73func.cpp

link73:
	g++ project73.o project73func.o -o run73.out

run73:
	./run73.out
