#include <iostream>
#include <vector>
#include <string>
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

int main() {
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
    }

    file.close();

    cout << "Acabado" << endl; 
} 