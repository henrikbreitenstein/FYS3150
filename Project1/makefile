all: compile link run

compile:
	g++ -c main.cpp -o main.o

link:
	g++ main.o -o main.out

run:
	./main.out

solveall: csolve slink srun

csolve:
	g++ -c solve.cpp -o solve.o

slink:
	g++ solve.o -o solve.out -larmadillo

srun:
	./solve.out

pr7all: prc prlink prun

prc:
	g++ -c Problem73.cpp Problem73func.cpp

prlink:
	g++ Problem73.o Problem73func.o

prun:
	./a.out
