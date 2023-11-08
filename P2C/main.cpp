#include "cambio.h"
#include <iostream>

int main() {
    int cantidad, N_monedas;
    std::cout << "Ingrese la cantidad de cambio a devolver: ";
    std::cin >> cantidad;

    std::cout << "Ingrese el número de monedas a utilizar: ";
    std::cin >> N_monedas;

    int* v = new int[N_monedas];
    std::cout << "Ingrese las denominaciones de monedas:\n";
    for (int i = 0; i < N_monedas; i++) {
        std::cin >> v[i];
    }

    std::cout << "   ";
    for (int i = 0; i <= cantidad; i++) {
        std::cout << i << "    ";
    }
    std::cout << std::endl;

    int* resultado = cambio_vector(N_monedas, v, cantidad);

    std::cout << "El vector solución óptima es:" << std::endl;
    std::cout << "x = [";
    for (int x = 0; x < N_monedas; x++) {
        if (x == N_monedas - 1) {
            std::cout << resultado[x];
        } else {
            std::cout << resultado[x] << ", ";
        }
    }
    std::cout << "]" << std::endl;

    delete[] v; // Liberar la memoria asignada al vector v

    return 0;
}

