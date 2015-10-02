SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g -std=c++11 -O3 -lrt  -I$(INC) -c

all: $(BIN)/mochila 
#................................................
#	EJECUTABLES

$(BIN)/mochila: $(OBJ)/mochila.o $(OBJ)/mult_clas.o
	@echo Construyendo mochila...
	$(CXX) -o $(BIN)/mochila $(OBJ)/mochila.o $(OBJ)/mult_clas.o

#................................................
# 	FICHEROS OBJETO

$(OBJ)/mochila.o: $(SRC)/mochila_branch_bound.cpp
	@echo Construyendo mochila.o...
	$(CXX) $(CPPFLAGS) $(SRC)/mochila_branch_bound.cpp -o $(OBJ)/mochila.o -I$(INC)

#................................................
#	OPCIONES DE LIMPIEZA

clean:
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper: clean
	-rm $(BIN)/*