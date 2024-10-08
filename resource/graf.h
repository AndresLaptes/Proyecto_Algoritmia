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
        T stringToT(const string& a);
    public:
    
    Graf(const T& val);
    Graf();
    ~Graf();

    void insert_vertice(const T& val, Node* &aux);
    void remove_vertice(const T& val);
    void insert_aresta(const T& a, const T& b);
    void remove_aresta(const T& a, const T& b);

    void read(ifstream& file);

    bool exist(const T& val) const;
    int size() const;
    void print();



};
#include "Graf_impl.h"
#endif