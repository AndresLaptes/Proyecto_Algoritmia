#ifndef GRAF_H
#define GRAF_H

#include <iostream>
#include <vector>
#include <stack>
#include <list>
using namespace std;

class grafo
{
<<<<<<< HEAD
    private:                
        list<pair<int, list<int>>> vertices;
        void remove_one_direction(int n, int v); 
        void DFS(int v, vector<bool>& visitados);

    public:
        grafo();
        grafo(int v, const list<int>& arestas);   

        void copia_grafo(list<pair<int, list<int>>> aux);

        void insert_vertice(int v);
        void remove_vertice(int v);
        void insert_aresta(int v, int v2);
        void remove_aresta(int v, int v2);
=======
    private:
        list<pair<int, list<int>>> vertices;
    public:
        grafo();
        grafo(int v, const list<int>& arestas);   
>>>>>>> PabloCalomardo

        int size() const;
        int CC(int v);
        bool exist(int v) const;
        bool exist_conection(int v1, int v2) const;
        void print() const;

<<<<<<< HEAD
        list<pair<int, list<int>>> get_vertices() const;

=======
        void insert_vertice(int v);
        void remove_vertice(int v);
        void insert_aresta(int v, int v2);
        void remove_aresta(int v, int v2);

        int size() const;
        bool exist(int v) const;
        bool exist_conection(int v1, int v2) const;
        void print() const;

>>>>>>> PabloCalomardo
        void read(ifstream& file);
        void write(ofstream& file);
};


#include "Graf_impl.h"
#endif