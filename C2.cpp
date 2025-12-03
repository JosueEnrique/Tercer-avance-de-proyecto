#include <iostream>
#include <cmath>
using namespace std;

void hanoiIterativo(int n, char origen, char destino, char auxiliar) {
    int totalMovimientos = pow(2, n) - 1;

    // Si el número de discos es par, se intercambian destino y auxiliar
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

int main() {
    int discos;
    cout << "Ingrese el número de discos: ";
    cin >> discos;

    if (discos <= 0) {
        cout << "Número inválido de discos. Debe ser mayor que 0." << endl;
    } else {
        cout << "\n--- Movimientos (Iterativo) ---\n";
        hanoiIterativo(discos, 'A', 'C', 'B');
    }

    return 0;
}
