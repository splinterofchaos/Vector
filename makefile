
CPP=g++
OPS=--std=c++0x
OUT=run

run: .Vector.h.o
	${CPP} ${OPS} -o ${OUT} main.cpp

.Vector.h.o: Vector.h
	${CPP} ${OPS} -o .Vector.h.o Vector.h

clean:
	rm .Vector.h.o run
