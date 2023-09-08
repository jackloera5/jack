#include  <iostream>


    //  función doubleNumber


int doubleNumber(int numero) {
    // Retorna el doble del número proporcionado
    return numero * 2;
}

int main() {
    int numero;
    
    // ingresae numero entero
    std::cout << "Ingrese un número entero: ";
    std::cin >> numero;

    // Llamar a la función doubleNumber para duplicar el número ingresado
    int resultado = doubleNumber(numero);

    // Imprimir
    std::cout << "El doble de " << numero << " es " << resultado << std::endl;

    return 0;
}
