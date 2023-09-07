#include <iostream>

int main() {
    double numero;

    
    std::cout << "Ingrese un número: ";  // Solicitar al usuario ingresar un número
    std::cin >> numero;

    
    double resultado = numero * 2;    // Multiplicar el número por 2

    
    std::cout << "El resultado de multiplicar " << numero << " por 2 es: " << resultado << std::endl;  // resultado

    return 0;
}
