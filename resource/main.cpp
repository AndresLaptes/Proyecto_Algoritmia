#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <iomanip>
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


//Percolacion de vertice
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

int main() {
    ofstream file("estadisticas.csv");
    file << "n vertices, p, p de transición" << endl;
    int nNodes[5] = {20, 50, 100, 150, 200}; //aqui pondria el numero de nodos que generaria para cada grafo

    for (int i = 0; i < 5; ++i) {
        double p = 0.000;

        ifstream grafos("input.csv");
        if (not grafos.is_open()) {
            cout << "No se puede abrir los grafos geometricos" << endl;
            break;
        }
 
        while (p <= 1.000) {
            grafo generados[10];
            for (int j = 0; j < 10; ++j) generados[j].read(grafos);
            
            double percolados = 0;
            double descartados = 0; //si generamos un grafo y este desde el principio no es connexo no podemos ver el cambio de fase
            for (int j = 0; j < 10; ++j) {
                if (generados[j].size() > 0) { //descartamos un grafo en dos casos, si inicialmente no es connexo o si es un grafo vacio.
                    int v = generados[j].get_element();
                    int componentes = generados[j].CC(v);

                    if (componentes > 1) ++descartados;
                    else {
                        bond_perlocation(generados[j], p);
                        componentes = generados[j].CC(v);
                        if (componentes > 1) ++percolados;
                    }
                } else ++descartados;
            }
            double p_trans = double(percolados/(10.0-descartados));
            file << std::fixed << std::setprecision(3);
            file << nNodes << "," << p << "," << p_trans << endl;
            p += 0.001;
        }
    }
}