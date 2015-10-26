SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g -std=c++11 -O3 -lrt  -I$(INC) -c

all: $(BIN)/MochilaDinamica

$(BIN)/MochilaDinamica: $(OBJ)/MochilaDinamica.o
	@echo Construyendo MochilaDinamica...
	$(CXX) -o $(BIN)/MochilaDinamica $(OBJ)/MochilaDinamica.o 

$(OBJ)/MochilaDinamica.o: $(SRC)/mochila_bp.cpp 
	@echo Construyendo MochilaDinamica.o...
	$(CXX) $(CPPFLAGS) $(SRC)/mochila_bp.cpp -o $(OBJ)/MochilaDinamica.o -I$(INC)

#-------------------------------------------------------------------------------
#  ORDENES DE LIMPIEZA
#-------------------------------------------------------------------------------

clean:
	-rm -v $(OBJ)/* 

mrproper: clean
	-rm -v $(BIN)/*