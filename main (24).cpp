#include <iostream>
                       //En C++, las funciones deben definirse de manera independiente
                      // y no pueden estar anidadas dentro de otras funciones. En tu
int return7()          // código, estás tratando de definir la función return9()
                       // dentro de la función return7(), lo cual no está permitido en C++.
{
    return 7;
    
    int return9()
    {
        return 9;
    }
}
int main()
{
    std::cout << return7() + return9() << '\n';
    
    return 0;
    
    
}