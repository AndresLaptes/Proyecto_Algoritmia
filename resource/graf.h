#ifndef GRAF_H
#define GRAF_H

#include <iostream>
#include <list>
using namespace std;

template <typename T> class Graf {
    private:
        struct Node {
            T vertice;
            list<Node*> arestas;
        };

        list<Node*> vertices;
    public:
    
    Graf(const T& val);
    Graf();
    ~Graf();

    void insert_vertice(const T& val);
    void remove_vertice(const T& val);
    void insert_aresta(const T& a, const T& b);
    void remove_aresta(const T& a, const T& b);

    int size() const;



};
#include "Graf_impl.h"
#endif