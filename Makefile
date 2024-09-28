#Variables
COP = g++
FLAGS = -Wall -std=c++11 -g -I./resource
NAME = main

OBJ = main.o

all: $(NAME)

$(NAME): $(OBJ)
	$(COP) $(FLAGS) -o $(NAME) $(OBJ)

main.o: rsc/main.cpp
	$(COP) $(FLAGS) -c rsc/main.cpp

clean: 
	rm -f $(OBJ) $(NAME) *.h.gch *.o res.txt