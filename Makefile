SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


all: $(BIN)/testdiccionario $(BIN)/letras $(BIN)/cantidad_letras
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************
# ************ testdiccionario ************
$(BIN)/testdiccionario : $(OBJ)/diccionario.o $(OBJ)/testdiccionario.o
	$(CXX) -o $(BIN)/testdiccionario $(OBJ)/diccionario.o $(OBJ)/testdiccionario.o

$(OBJ)/diccionario.o : $(SRC)/diccionario.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/diccionario.o $(SRC)/diccionario.cpp

$(OBJ)/testdiccionario.o : $(SRC)/testdiccionario.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/testdiccionario.o $(SRC)/testdiccionario.cpp

# ************ letras ************
$(BIN)/letras : $(OBJ)/diccionario.o $(OBJ)/letra.o $(OBJ)/conjunto_letras.o $(OBJ)/bolsa_letras.o $(OBJ)/letras.o
	$(CXX) -o $(BIN)/letras $(OBJ)/diccionario.o $(OBJ)/letra.o $(OBJ)/conjunto_letras.o $(OBJ)/bolsa_letras.o $(OBJ)/letras.o

$(OBJ)/letra.o : $(SRC)/letra.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/letra.o $(SRC)/letra.cpp

$(OBJ)/conjunto_letras.o : $(SRC)/conjunto_letras.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/conjunto_letras.o $(SRC)/conjunto_letras.cpp

$(OBJ)/bolsa_letras.o : $(SRC)/bolsa_letras.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/bolsa_letras.o $(SRC)/bolsa_letras.cpp

$(OBJ)/letras.o : $(SRC)/letras.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/letras.o $(SRC)/letras.cpp

# ************ cantidad_letras ************
$(BIN)/cantidad_letras : $(OBJ)/diccionario.o $(OBJ)/letra.o $(OBJ)/conjunto_letras.o $(OBJ)/cantidad_letras.o
	$(CXX) -o $(BIN)/cantidad_letras $(OBJ)/diccionario.o $(OBJ)/letra.o $(OBJ)/conjunto_letras.o $(OBJ)/cantidad_letras.o

$(OBJ)/cantidad_letras.o : $(SRC)/cantidad_letras.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/cantidad_letras.o $(SRC)/cantidad_letras.cpp


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
