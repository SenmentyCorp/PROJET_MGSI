CC=g++
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=PROJET
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS) -lGL -lglut -lGLEW  -lm -lGLU -larmadillo -llapack -lblas
	@make clean

main.o: main.cpp
	g++ -c -Wall main.cpp

%.o: %.cpp
	@$(CC) -o $@ -c $< $(CFLAGS) 

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)
