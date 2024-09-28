#include <graf.h>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    ifstream file("grafos.csv");
    if (not file.is_open()) cout << "No se puede abrir" << endl; 
    for (int i = 0; i < 2; ++i) {
        Graf<int> actual;
        actual.read(file);
        cout << "Grafo: "<< i << endl;
        actual.print();
        cout << endl;
    }

    file.close();

    cout << "Acabado" << endl; 
} 