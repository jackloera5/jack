#include <iostream>  // Incluye la biblioteca para entrada/salida estándar.

// Función que suma tres enteros y devuelve el resultado.
int add(int x, int y, int z)
{
    return x + y + z;
}

// Función que multiplica dos enteros y devuelve el resultado.
int multiply(int x, int y)
{
    return x * y;
}

int main()
{
    // Llama a la función multiply() con el resultado de add(1, 2, 3) como primer argumento y 4 como segundo argumento.
    // Imprime el resultado en la consola.
    std::cout << multiply(add(1, 2, 3), 4) << '\n';
    
    return 0;  // Devuelve 0 como valor de salida del programa para indicar que se ejecutó correctamente.
}
