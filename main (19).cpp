#include <iostream>

int getValueFromUser() // esta función ahora devuelve un valor entero
{
    std::cout << "Ingrese un entero: ";
    int input{};
    std::cin >> input; // Corrige el nombre de la variable de "entrada" a "input"
    
    return input; // Devuelve el valor que el usuario ingresó
}

int main()
{
    int num{ getValueFromUser() }; // Inicializa num con el valor de retorno de getValueFromUser
    std::cout << num << " duplicado es: " << num * 2 << '\n';

    return 0;
}
