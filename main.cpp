#include <iostream>
#include <string>
using namespace std;

void Usage() {
    cout << "Para seleccionar una experimento escriba la letra en mayuscula del apartado respectivo" << endl;
    cout << "Para acabar el programa escriba 'end'" << endl;
    cout << "Los experimentos validos son C, D, E" << endl;
    cout << endl;

    cout << "Al utilizar el experimento C hay que cambiar el PATH absoluto del ordenador actual" << endl;
    cout << "Modificar de resource/ExperimentoC/ExperimentoC.cpp la linea 101" << endl;

    cout << endl;
}

void ExperimentoE();
void ExperimentoC();
void ExperimentoD();

int main() {
    Usage();
    string exp = "act";
    while (exp != "end") {
        cout << "Seleccione el experimento" << endl;
        cin >> exp;
        if (exp == "C") {
            cout << "Experimento de graellas cuadradas" << endl;
            ExperimentoC();
        } else if (exp == "D") {
            cout << "Experimento de grafos triangulados" << endl;
            ExperimentoD();
        } else if (exp == "E") {
            cout << "Experimento de grafos geometricos" << endl;
            ExperimentoE();
        } else if (exp != "end") cout << "Seleccione un experimento valido" << endl << endl;

    }
}