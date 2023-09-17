#include <iostream>

void doSemething()
{
    std::cout << "hola \n"
    
}

int main ()
{
    int x {0};//la vida de x comienza aqui 
    doSemething();// x sigue vivo durante esta funcion 
    return 0;
    
}// la vida de x termina aqui 