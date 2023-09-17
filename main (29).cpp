//#include <iostream>  // Incluye la biblioteca iostream que permite la entrada y salida estándar.

//int returnFive()  // Define una función llamada returnFive que devuelve un valor entero.
//{
//    return 5;  // Retorna el valor entero 5 cuando se llama a la función.
//}

//int main()  // La función principal del programa.
//{
//    std::cout << returnFive << '\n';  // Intenta imprimir la dirección de la función returnFive, no su valor de retorno.

//    return 0;  // Indica que el programa se ejecutó correctamente y devuelve un valor de salida 0 al sistema operativo.
//}  este programa sin corregir imprimiria un 1 en consola lo cual no keremos asi kedaria ya corregido


#include <iostream>  // Incluye la biblioteca iostream que permite la entrada y salida estándar.

int returnFive()  // Define una función llamada returnFive que devuelve un valor entero.
{
    return 5;  // Retorna el valor entero 5 cuando se llama a la función.
}

int main()  // La función principal del programa.
{
   std::cout << returnFive() << '\n';  // Llama a la función returnFive y muestra su valor de retorno en la consola.


    return 0;  // Indica que el programa se ejecutó correctamente y devuelve un valor de salida 0 al sistema operativo.
}

