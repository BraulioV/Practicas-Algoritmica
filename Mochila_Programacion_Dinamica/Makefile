SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g -std=c++11 -O3 -lrt  -I$(INC) -c

all: $(BIN)/mochila $(BIN)/MochilaDinamica

$(BIN)/mochila: $(OBJ)/mochila.o
	@echo Construyendo mochila...
	$(CXX) -o $(BIN)/mochila $(OBJ)/mochila.o 

$(BIN)/MochilaDinamica: $(OBJ)/MochilaDinamica.o
	@echo Construyendo MochilaDinamica...
	$(CXX) -o $(BIN)/MochilaDinamica $(OBJ)/MochilaDinamica.o 

$(OBJ)/mochila.o: $(SRC)/mochila.cpp 
	@echo Construyendo mochila.o...
	$(CXX) $(CPPFLAGS) $(SRC)/mochila.cpp -o $(OBJ)/mochila.o -I$(INC)

$(OBJ)/MochilaDinamica.o: $(SRC)/mochila_bp.cpp 
	@echo Construyendo MochilaDinamica.o...
	$(CXX) $(CPPFLAGS) $(SRC)/mochila_bp.cpp -o $(OBJ)/MochilaDinamica.o -I$(INC)