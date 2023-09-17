#include <iostream>  // Incluye la biblioteca iostream que permite la entrada y salida estándar.

int getNumbers()  // Define una función llamada getNumbers que devuelve un valor entero.
{
    return 5;  // Retorna el valor entero 5 inmediatamente cuando se llama a la función.
    return 7;  //  "ojo"Este return nunca se alcanza ya que se encuentra después del primer return.
}

int main()  // La función principal del programa.
{
    std::cout << getNumbers() << '\n';  // Llama a la función getNumbers y muestra su resultado en la consola.
    std::cout << getNumbers() << '\n';  // Llama nuevamente a la función getNumbers y muestra su resultado en la consola.

    return 0;  // Indica que el programa se ejecutó correctamente y devuelve un valor de salida 0 al sistema operativo.
}
