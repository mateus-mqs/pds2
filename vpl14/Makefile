CC=g++
CFLAGS=-std=c++11 -Wall

BUILD= ./build
INCLUDE= ./include
ENTIDADES= ./src/entidades
SRC = ./src

all:vpl_execution

${BUILD}/Cilindro.o: ${INCLUDE}/Cilindro.hpp ${ENTIDADES}/Cilindro.cpp
	${CC} ${CFLAGS} -I ${INCLUDE} -c ${ENTIDADES}/Cilindro.cpp -o ${BUILD}/Cilindro.o

${BUILD}/Circulo.o: ${INCLUDE}/Circulo.hpp ${ENTIDADES}/Circulo.cpp
	${CC} ${CFLAGS} -I ${INCLUDE} -c ${ENTIDADES}/Circulo.cpp -o ${BUILD}/Circulo.o

${BUILD}/Ponto.o: ${INCLUDE}/Ponto.hpp ${ENTIDADES}/Ponto.cpp
	${CC} ${CFLAGS} -I ${INCLUDE} -c ${ENTIDADES}/Ponto.cpp -o ${BUILD}/Ponto.o

${BUILD}/main.o: ./src/main.cpp ${INCLUDE}/Cilindro.hpp ${INCLUDE}/Circulo.hpp ${INCLUDE}/Ponto.hpp
	${CC} ${CFLAGS} -I ${INCLUDE} -c ${SRC}/main.cpp -o ${BUILD}/main.o

vpl_execution: ${BUILD}/main.o ${BUILD}/Cilindro.o ${BUILD}/Circulo.o ${BUILD}/Ponto.o
	${CC} ${CFLAGS} -o vpl_execution ${BUILD}/main.o ${BUILD}/Cilindro.o ${BUILD}/Circulo.o ${BUILD}/Ponto.o

clean:
	rm -f main ${BUILD}/*.o
	