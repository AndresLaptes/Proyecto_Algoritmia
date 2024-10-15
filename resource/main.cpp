#include <iostream>
#include <vector>
<<<<<<< HEAD
#include <string>
#include <random>
#include "Graf_impl.h"
using namespace std;

//Genera un graf amb n vèrtex i amb la probabilitat p de generar arestes entre vèrtexs
grafo genera_random(int n, float p) {
    grafo G;
    int pr = p*100;
    for (int i = 0; i < n; ++i) G.insert_vertice(i);  //Afegeix el node i al graf
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            int r = rand()%100;
            if (r < pr) G.insert_aresta(i,j); //Afegeix al node i una aresta al node j
        }
    }
    return G;
}

void site_perlocation(grafo& grafo, double p) {

    //Generar distribucio aleatoria
    random_device gen_rand;
    default_random_engine generator(gen_rand());
    uniform_real_distribution<double> distribution(0,1);  

    double a; 
    list<pair<int, list<int>>> aux1 = grafo.get_vertices();
    for (auto itr = aux1.begin(); itr != aux1.end(); ++itr) {
        a = distribution(generator);
        if (a > (1-p)) {
            grafo.remove_vertice((*itr).first);
        }  
    }  
}

//percolacion de arestas
void bond_perlocation(grafo& grafo, double p) {

    random_device gen_rand;
    default_random_engine generator(gen_rand());
    uniform_real_distribution<double> distribution(0,1);


    double a;
    list<pair<int, list<int>>> aux1 = grafo.get_vertices();

    for (auto itr = aux1.begin(); itr != aux1.end(); ++itr) {
        for (auto itr2 = (*itr).second.begin(); itr2 != (*itr).second.end(); ++itr2) {
            a = distribution(generator);
            if (a > (1-p)) {
                grafo.remove_aresta((*itr).first, (*itr2));
            }  
        }
    }
}

void ejemplo() {
    ifstream file("grafos.csv");
    if (not file.is_open()) cout << "No se puede abrir" << endl; 
    for (int i = 0; i < 2; ++i) {
        grafo actual = genera_random(10,0.5);
        cout << "Grafo: "<< i << endl;
        actual.print();
        cout << endl;
        string filename;
        if (i == 0) filename = "Graf1.csv";
        else filename = "Graf2.csv";
        ofstream outfile(filename);
        actual.write(outfile);
        file.close();
        double p;
        cout << "Introdueix probabilitat de percolacio" << endl;
        p = 0.5;
        if (p >= 0.0 or p <= 1.0) {
            if (i == 0) site_perlocation(actual,p);
            else bond_perlocation(actual,p);
            if (i == 0) filename = "Graf1_site_perc.csv";
            else filename = "Graf2_bond_perc.csv";
            ofstream outfile(filename);
            actual.write(outfile);
            file.close();
        }
    }


    file.close();

    cout << "Acabado" << endl; 
} 