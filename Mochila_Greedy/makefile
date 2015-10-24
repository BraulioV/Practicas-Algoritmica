SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g -std=c++11 -O3 -lrt  -I$(INC) -c

all: $(BIN)/mochila 
#................................................
#	EJECUTABLES

$(BIN)/mochila: $(OBJ)/mochila.o $(OBJ)/mochila.o
	@echo Construyendo mochila...
	$(CXX) -o $(BIN)/mochila $(OBJ)/mochila.o

#................................................
# 	FICHEROS OBJETO

$(OBJ)/mochila.o: $(SRC)/Greedy.cpp
	@echo Construyendo mochila.o...
	$(CXX) $(CPPFLAGS) $(SRC)/Greedy.cpp -o $(OBJ)/mochila.o -I$(INC)

#................................................
#	OPCIONES DE LIMPIEZA

clean:
	-rm -v $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper: clean
	-rm -v $(BIN)/*