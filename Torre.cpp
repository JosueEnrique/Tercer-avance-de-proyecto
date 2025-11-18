#include <iostream>
#include <cmath>    

using namespace std;

// Función recursiva para resolver la Torre de Hanoi
// n        : número de discos
// origen   : poste desde donde se mueven los discos
// auxiliar : poste de apoyo
// destino  : poste al que queremos llevar la torre
void torreDeHanoi(int n, char origen, char auxiliar, char destino) {
    // Caso base: solo un disco, se mueve directamente de origen a destino
    if (n == 1) {
        cout << "Mover disco 1 de " << origen << " a " << destino << endl;
    } else {
        // 1. Mover n-1 discos de origen a auxiliar, usando destino como apoyo
        torreDeHanoi(n - 1, origen, destino, auxiliar);

        // 2. Mover el disco más grande (n) de origen a destino
        cout << "Mover disco " << n << " de " << origen << " a " << destino << endl;

        // 3. Mover los n-1 discos de auxiliar a destino, usando origen como apoyo
        torreDeHanoi(n - 1, auxiliar, origen, destino);
    }
}

// ---------------------------------------------------------
// Muestra el número mínimo de movimientos (sucesión 2^n - 1)
// ---------------------------------------------------------
long long movimientosMinimos(int n) {
    return static_cast<long long>(pow(2, n)) - 1;
}


// Menú principal
int main() {
    int opcion;

    do {
        cout << "\n===== MENU PRINCIPAL =====" << endl;
        cout << "1. Resolver Torre de Hanoi" << endl;
        cout << "0. Salir" << endl;
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int discos;
                cout << "\n--- TORRE DE HANOI ---" << endl;
                cout << "Ingresa el numero de discos: ";
                cin >> discos;

                if (discos <= 0) {
                    cout << "El numero de discos debe ser mayor que 0." << endl;
                } else {
                    cout << "\nPasos para resolver la Torre de Hanoi con "
                         << discos << " discos:\n" << endl;
                    torreDeHanoi(discos, 'A', 'B', 'C');

                    cout << "\nNumero minimo de movimientos: "
                         << movimientosMinimos(discos) << endl;
                }
                break;
            }

            case 0:
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << "Opcion no valida. Intenta de nuevo." << endl;
        }

    } while (opcion != 0);

    return 0;
}