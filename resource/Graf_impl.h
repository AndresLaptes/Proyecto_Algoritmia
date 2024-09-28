#ifndef GRAF_IMPL_H
#define GRAF_IMPL_H

#include <graf.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <stdexcept>
using namespace std;

template <typename T>
Graf<T>::Graf(const T& value) {
    Node *nuevo = new Node;
    nuevo->vertice = value;
    vertices.push_front(nuevo);
}


template <typename T> 
Graf<T>::~Graf() {
    for (auto& node : vertices) delete node;
    vertices.clear();
}

template <typename T>
Graf<T>::Graf() {}

template <typename T>
int Graf<T>::size() const {
    return vertices.size();
}

template <typename T>
bool Graf<T>::exist(const T& val) const {
    for (auto it : vertices) {
        if (it->vertice == val) return true;
    }
    return false;
}

template <typename T>
void Graf<T>::insert_vertice(const T& val, Node* &aux) {
    Node *nuevo = new Node;
    nuevo->vertice = val;
    vertices.push_front(nuevo);
    aux = nuevo;
}

template <typename T>
void Graf<T>::remove_vertice(const T& val) {
    for (auto it = vertices.begin(); it != vertices.end(); ++it) {
        if ((*it)->vertice == val) {
            delate (*it);
            vertices.erase(it);
            break;
        }
    }
}

template <typename T>
void Graf<T>::insert_aresta(const T& a, const T&b) {
    bool found = false;
    if (a == b) {
        string msg = "Error: son el mismo vertice";
        throw invalid_argument(msg);
    }


    Node *A = nullptr;
    Node *B = nullptr;
    for (auto& node : vertices) {
        if (node->vertice == a) A = node;
        else if (node->vertice == b) B = node;
    }

    if (A == nullptr) {
        insert_vertice(a, A);
    }
    if (B == nullptr) {
        insert_vertice(b, B);
    }

    for (auto& it : A->arestas) {
        if (it == B) {
            found = true;
            break;
        }
    }

    if (not found) {
        A->arestas.push_front(B);
        B->arestas.push_front(A);
    }
} 

template <typename T> 
void Graf<T>::remove_aresta(const T& a, const T& b) {
        bool found = false;
    if (a == b) {
        string msg = "Error: son el mismo  vertice";
        throw invalid_argument(msg);
    }


    Node *A = nullptr;
    Node *B = nullptr;
    for (auto& node : vertices) {
        if (node->vertice == a) A = node;
        else if (node->vertice == b) B = node;
    }

    if (A == nullptr) {
        string msg = "Error: tu primer nodo no existe";
        throw invalid_argument(msg);
    }

    if (B == nullptr) {
        string msg = "Error: tu segundo nodo no existe";
        throw invalid_argument(msg);
    }

    for (auto& it : A->conections) {
        if (it == B) {
            delete it;
            found = true;
            break;
        }
    }

    if (found) {
        for (auto& it : B->conections) {
            if (it == A) {
                delete it;
                found = true;
                break;
            }
        }
    } else throw invalid_argument("Error: tu aresta entre los vertices dados no existe");
}

template <typename T> 
void Graf<T>::read(ifstream& file) {
    string linea;
    while (getline(file, linea)) {
        if (not linea.empty()) {
            stringstream line(linea);

            string vertice;
            getline(line, vertice, ',');
            Node *nosirve = new Node;
            if (not exist(stringToT(vertice))) insert_vertice(stringToT(vertice), nosirve);

            string arestas;
            while (getline(line, arestas, ',')) {
                insert_aresta(stringToT(vertice), stringToT(arestas));
            }
            
        } else break;
    }
}

template <typename T>
T Graf<T>::stringToT(const string& a) {
    T value;
    std::istringstream iss(a);
    iss >> value;

    if (iss.fail()) {
        throw std::invalid_argument("Error al convertir string a tipo T.");
    }

    return value;
}

template <typename T>
void Graf<T>::print() {
    for (auto& nodo : vertices) {
        cout << "En la direccion (" << nodo << ") hay un nodo con valor: " << nodo->vertice << " con las siguientes conexiones : ";
        auto end = nodo->arestas.end();
        for (auto it = nodo->arestas.begin(); it != end; ++it) cout << (*it)->vertice << " ";
        cout << endl; 
    }
}

#endif
