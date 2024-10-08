#include <iostream>
#include <list>
#include "graf.h" 
#include <cstdlib>
#include <ctime>

using namespace std;
double p;

void site_perlocation(Graf<int> grafo) {
    auto itr = grafo.vertices.begin();
    double a;
    for (auto itr = grafo.vertices.begin(); itr != grafo.vertices.end(); ++itr) {
        //Generar a random
        if (a > (1-p)) {
            grafo.remove_vertice(itr->vertex);
        }  
    }  

}


void bond_perlocation(Graf<int> grafo) {

    auto itr = grafo.vertices.begin();
    double a;
    for (auto itr = grafo.vertices.begin(); itr != grafo.vertices.end(); ++itr) {
        for (auto itr2 = itr->conections.begin(); itr2 != itr->conections.end(); ++itr2) {
            //Generar a random
            if (a > (1-p)) {
                grafo.remove_aresta();
            }  
        }
    } 
}

void main () {
    cout << "Inici del Programa" << endl;
    
    Graf<int> grafo;
    
    ifstream file ("grafos.csv");
    if (not file.is_open()) cout << "Error: No se puedo abrir el archivo grafos.csv" << endl;
    grafo.read(file);

    cout << "Indiqui el tipus de perlocació [Vertex/Arestes]:" << endl;
    string Percolation_type;
    cin >> Percolation_type;

    cout << "Indiqui la probabilidad de perlocacio:" << endl;
    cin >> p;


    if (Percolation_type == "Vertex") {
        site_perlocation(grafo);
    } else if (Percolation_type == "Arestes") {
        bond_perlocation(grafo);
    } else cout << "Error: Input no valid";
    
    file.close();
    cout << "Programa finalitzat" << endl;
}