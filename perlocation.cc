#include <iostream>
#include <list>
#include "graf.h" 
#include <vector>
#include <random>

using namespace std;
double p;

void site_perlocation(grafo& grafo) {

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
    grafo.copia_grafo(aux1);

}


void bond_perlocation(grafo& grafo) {

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
    grafo.copia_grafo(aux1);

}

int main () {
    cout << "Inici del Programa" << endl;
    cout << "Nombre de grafs a tractar:__" << endl;
    int numG; 
    cin >> numG;
    vector<grafo> G(numG); 

    ifstream file ("grafos.csv");
    if (not file.is_open()) cout << "Error: No se puedo abrir el archivo grafos.csv" << endl;

    for (int i = 0; i < numG; ++i) {
        grafo aux;
        aux.read(file);
        G[i] = aux;        

    }
    file.close();

    cout << "Indiqui la probabilidad de perlocacio, valors [0,1]:" << endl;
    cin >> p;
    while (p > 1.0) {
        cout << "Error: Probabilitat major que 1, indiqui un altre valor en [0,1]" << endl;
        cin >> p;
    }


    cout << "Inici perlocacio per nodes" << endl;
    for (int i = 0; i < numG; ++i) {
        site_perlocation(G[i]);
        cout << "pfin"<< endl;

        cout << "Graf " << i << " perlocat" << endl;
        
        //Guardem el graf perlocat
        string name = "grafo";
        name += to_string(i) + ".csv";
        ofstream nuevo(name);
        G[i].write(nuevo);
        nuevo.close(); 
    }
    cout << "Inici perlocacio per arestes" << endl;
    for (int i = 0; i < numG; ++i) {
        bond_perlocation(G[i]);
        cout << "Graf " << i << " perlocat" << endl;
        
        //Guardem el graf perlocat
        string name = "grafo";
        name += to_string(i) + ".csv";
        ofstream nuevo(name);
        G[i].write(nuevo);
        nuevo.close(); 
    }

    cout << "Totes les perlocacions han finalitzat/n Programa finalitzat" << endl;

}