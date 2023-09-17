#include <iostream>  // Incluye la biblioteca iostream que permite la entrada y salida estándar.



int getValueFromUser()  // Define una función llamada getValueFromUser que solicita al usuario un entero y lo devuelve.
{
    
    
    
    std::cout << "Ingrese un entero: ";  // Muestra un mensaje
    int input{};  // Declara una variable llamada 'input' para almacenar el número ingresado.
    std::cin >> input;  // Lee un entero desde la entrada estándar (teclado) y lo almacena en 'input'.
    
    
    
    return input;  // Retorna el valor ingresado por el usuario.
}


int doubleValue(int value)  // Define una función llamada doubleValue que toma un entero como argumento y devuelve su doble.
{
    return value * 2;  // Retorna el doble del valor pasado como argumento.
}



int main()  // La función principal del programa.
{
    
    
    int num = getValueFromUser();  // Llama a la función getValueFromUser y almacena el valor ingresado en la variable 'num'.
    int doubleNum = doubleValue(num);  // Llama a la función doubleValue para calcular el doble de 'num' y lo almacena en 'doubleNum'.
    
    std::cout << num << " el doble de es: " << doubleNum << '\n';  // Muestra el número original y su doble en la consola.
    
    return 0;  // 



}
