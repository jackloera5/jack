#include <iostream>
#include <cmath>

bool esEntero(float numero) {
    return numero == floor(numero);
}

int main() {
    float numero;

    std::cout << "Introduce un número: ";
    std::cin >> numero;

    if (esEntero(numero)) {
        std::cout << "El número es entero." << std::endl;
    } else {
        std::cout << "El número no es entero." << std::endl;
    }

    return 0;
}