#ifndef GRAF_IMPL_H
#define GRAF_IMPL_H

#include "graf.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <stdexcept>
using namespace std;


grafo::grafo() {

}

grafo::grafo(int v, const list<int>& arestas) {
    list<int> aux = arestas;
    vertices.push_back({v,aux});
}

void grafo::insert_vertice(int v) {
    list<int> aux;
    vertices.push_back({v,aux});
}

void grafo::remove_vertice(int v) {
    for (auto it = vertices.begin(); it != vertices.end(); ++it) {
        if ((*it).first == v) {
            vertices.erase(it);
        }
    }
}

void grafo::insert_aresta(int v1, int v2) {
    if (not exist_conection(v1, v2) and exist(v1) and exist(v2)) {
        for (auto it = vertices.begin(); it != vertices.end(); ++it) {
            if ((*it).first == v1) (*it).second.push_back(v2);
            else if ((*it).first == v2) (*it).second.push_back(v1);
        }
    }
}

bool grafo::exist_conection(int v1, int v2) const {
    for (auto& it1 : vertices) {
        if (it1.first == v1) {
            for (auto& it2 : it1.second) {
                if (it2 == v2) return true;
            }
        }
    }
    return false;
}

void grafo::remove_aresta(int v1, int v2) {
    for (auto it = vertices.begin(); it != vertices.end(); ++it) {
        if ((*it).first == v1) {
            for (auto it2 = (*it).second.begin(); it2 != (*it).second.end(); ++it2) {
                if ((*it2) == v2) (*it).second.erase(it2);
            }
        }

        if ((*it).first == v2) {
            for (auto it2 = (*it).second.begin(); it2 != (*it).second.end(); ++it2) {
                if ((*it2) == v1) (*it).second.erase(it2);
            }
        }
    }
}

void grafo::read(ifstream& file) {
    string linea;
    while(getline(file, linea)) {
        if (not linea.empty()) {
            stringstream line(linea);

            string vertice;
            getline(line, vertice, ',');
            if (not exist(stoi(vertice))) insert_vertice(stoi(vertice));
            
            string arestas;
            while (getline(line, arestas, ',')) {
                insert_aresta(stoi(vertice), stoi(arestas));
            }
        } else break;
    }
}

void grafo::write(ofstream& file) {
    for (auto& vertice : vertices) {
        file << to_string(vertice.first);
        for (auto& aresta : vertice.second) {
            file << "," << to_string(aresta);
        }
        file << endl;
    }
}

void grafo::print() const {
    for (auto& v : vertices) {
        cout << "Soy " << v.first << " con numero de arestas " << v.second.size() << " y estamos conectado a : ";
        for (auto& a : v.second) {
            cout << a << " ";
        }
        cout << endl;
    }
}

int grafo::size() const {
    return vertices.size();
}

bool grafo::exist(int v) const {
    for (auto& i : vertices) {
        if (i.first == v) return true;
    }
    return false;
}

#endif