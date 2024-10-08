#include <graf.h>
#include <vector>
#include <iostream>
using namespace std;

//Genera un graf amb n vèrtex i amb la probabilitat p de generar arestes entre vèrtexs
 Graf genera_random(int n, float p) {
    Graf G = new Graf();
    int pr = p*100;
    for (int i = 0; i < n; ++i) {
        G.insert_vertice(i,null);  //Afegeix el node i al graf
        for (int j = 0; j < i; ++j) {
            int r = rand()%100;
            if (r < pr) G.insert_aresta(i,j); //Afegeix al node i una aresta al node j
        }
    }
}

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