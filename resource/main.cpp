#include <iostream>
#include <vector>
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
    
    string nomf;
    cout << "insereix en nom del fitxer si vols llegir els grafs des d'un csv, si no posa no" << endl;
    cin >> nomf;

    if(nomf != "no"){
        ifstream file(nomf);
    }

    if (not file.is_open()) cout << "No se puede abrir" << endl; 
    vector<grafo> a(2); 
    for (int i = 0; i < 2; ++i) {
        grafo aux;
        aux.read(file);
        a[i] = aux; 
    }

    cout << "Acabamos lectura" << endl;
    for (int i = 0; i < 2; ++i) a[i].print();
    file.close();

    int vertex;
    double prob;

    for (int i = 0; i < 2; ++i) {
        cout << "Posa el numero de vertex i la probabilitat" << endl;

        cin >> vertex >> prob;

        string name = "grafo";
        name += to_string(i) + ".csv";
        ofstream nuevo(name);
        a[i].write(nuevo);
        nuevo.close(); 
    }


    cout << "Acabado" << endl; 
    
} 