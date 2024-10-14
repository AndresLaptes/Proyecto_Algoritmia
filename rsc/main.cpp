#include "graf.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

int main() {
    ifstream file("grafos.csv");
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

    a[0].remove_vertice(1);
    ofstream file2("salida.csv");
    a[0].write(file2);
    file2.close();

    cout << "Acabado" << endl; 
    
} 