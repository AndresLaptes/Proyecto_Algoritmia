#Variables
COP = g++
FLAGS = -Wall -std=c++11 -g -I./resource
NAME = main

OBJ = main.o

all: $(NAME)

$(NAME): $(OBJ)
	$(COP) $(FLAGS) -o $(NAME) $(OBJ)

main.o: resource/main.cpp
	$(COP) $(FLAGS) -c resource/main.cpp

clean: 
	rm -f $(OBJ) $(NAME) *.h.gch *.o res.txt