#include <iostream>
#include <vector>
<<<<<<< HEAD
#include <string>
#include <random>
=======
>>>>>>> PabloCalomardo
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

<<<<<<< HEAD
void site_perlocation(grafo& grafo, double p) {

    //Generar distribucio aleatoria
    random_device gen_rand;
    default_random_engine generator(gen_rand());
    uniform_real_distribution<double> distribution(0,1);  

    cout << "pini"<< endl;
    double a; 
    list<pair<int, list<int>>> aux1 = grafo.get_vertices();
    for (auto itr = aux1.begin(); itr != aux1.end(); ++itr) {
        cout << "iteracion" << endl;
        a = distribution(generator);
        if (a > (1-p)) {
            cout << "p_rem"<< endl;
            grafo.remove_vertice((*itr).first);
            cout << "p_rem_fin"<< endl;
        }  
    }  
}


void bond_perlocation(grafo& grafo, double p) {

    random_device gen_rand;
    default_random_engine generator(gen_rand());
    uniform_real_distribution<double> distribution(0,1);

        cout << "pinia"<< endl;


    double a;
    list<pair<int, list<int>>> aux1 = grafo.get_vertices();

    for (auto itr = aux1.begin(); itr != aux1.end(); ++itr) {
            cout << "ini_for_2" << endl;
        for (auto itr2 = (*itr).second.begin(); itr2 != (*itr).second.end(); ++itr2) {
            a = distribution(generator);
            if (a > (1-p)) {
                cout << "p_rema"<< endl;
                grafo.remove_aresta((*itr).first, (*itr2));
                cout << "p_rema_fin"<< endl;
            }  
        }
    }
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
=======
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
    
>>>>>>> PabloCalomardo
} 