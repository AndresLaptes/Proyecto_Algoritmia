# Compilador
CXX = g++

# Flags de compilación
CXXFLAGS = -std=c++17 -Wall -Wextra -I./resource -I./resource/grafos

# Directorios
SRCDIR = .
BINDIR = .
OBJDIR = ./obj

# Archivos
MAIN = $(SRCDIR)/main.cpp
SRC_E = $(SRCDIR)/resource/ExperimentoE/ExperimentoE.cpp
SRC_D = $(SRCDIR)/resource/ExperimentoD/ExperimentoD.cpp
SRC_C = $(SRCDIR)/resource/ExperimentoC/ExperimentoC.cpp
SRC_GRAFO = $(SRCDIR)/resource/grafos/grafo.cpp

# Objetos
OBJ_MAIN = $(OBJDIR)/main.o
OBJ_E = $(OBJDIR)/ExperimentoE.o
OBJ_C = $(OBJDIR)/ExperimentoC.o
OBJ_D = $(OBJDIR)/ExperimentoD.o
OBJ_GRAFO = $(OBJDIR)/grafo.o

# Ejecutable
TARGET = $(BINDIR)/program

# Reglas
all: $(TARGET)

$(TARGET): $(OBJ_MAIN) $(OBJ_E) $(OBJ_C) $(OBJ_GRAFO) $(OBJ_D)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/main.o: $(MAIN)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJDIR)/ExperimentoE.o: $(SRC_E)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJDIR)/ExperimentoC.o: $(SRC_C)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJDIR)/ExperimentoD.o: $(SRC_D)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJDIR)/grafo.o: $(SRC_GRAFO)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJDIR)/*.o $(TARGET)

.PHONY: all clean
