#include "mochila.h"
#include <iostream>

int main() {
    int e;
    std::cout << "Ingrese la cantidad de elementos: ";
    std::cin >> e;

    int* p = new int[e];
    int* b = new int[e];

    std::cout << "Ingrese los pesos de los elementos:\n";
    for (int i = 0; i < e; i++) {
        std::cin >> p[i];
    }

    std::cout << "Ingrese los valores de los elementos:\n";
    for (int i = 0; i < e; i++) {
        std::cin >> b[i];
    }

    int M;
    std::cout << "Ingrese la capacidad de la mochila: ";
    std::cin >> M;

    int resultado = mochila(e, p, b, M);

    std::cout << "El valor máximo que se puede llevar en la mochila es: " << resultado << std::endl;

    int pesoTotal = 0;
    for (int i = 0; i < e; i++) {
        if (resultado >= b[i]) {
            pesoTotal += p[i];
            resultado -= b[i];
        } else {
            pesoTotal += p[i] * resultado / b[i];
            break;
        }
    }

    std::cout << "El peso total de los elementos seleccionados es: " << pesoTotal << std::endl;

    delete[] p;
    delete[] b;

    return 0;
}

