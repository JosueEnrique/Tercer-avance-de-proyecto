#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

struct Movimiento {
    int disco;
    char desde;
    char hacia;
};

void hanoiIterativo(int n, char origen, char destino, char auxiliar) {
    stack<Movimiento> pila;
    int totalMovimientos = pow(2, n) - 1;

    if (n % 2 == 0) swap(destino, auxiliar);

    for (int i = 1; i <= totalMovimientos; i++) {
        int disco = log2(i & -i) + 1;

        if (i % 3 == 1)
            cout << "Mover disco " << disco << " de " << origen << " a " << destino << endl;
        else if (i % 3 == 2)
            cout << "Mover disco " << disco << " de " << origen << " a " << auxiliar << endl;
        else
            cout << "Mover disco " << disco << " de " << auxiliar << " a " << destino << endl;
    }
}
