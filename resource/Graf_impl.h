#ifndef GRAF_IMPL_H
#define GRAF_IMPL_H

#include <graf.h>
#include <iostream>

template <typename T>
Graf<T>::Graf(const T& value) {
    Node *nuevo = new Node;
    nuevo->vertice = value;
    vertex.push_front(nuevo);
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
    return vertexs.size();
}

template <typename T>
void Graf<T>::insert_vertice(const T& val) {
    Node *nuevo = new Node;
    nuevo->vertice = val;
    vertices.push_front(nuevo);
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
            found = true;
            break;
        }
    }

    if (not found) {
        A->arestas.push_front(B);
        B->arestas.push_fornt(A);
    } else throw invalid_argument("Error ya existe una aresta entre tu primer vertice y tu segundo vertice");

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

#endif
