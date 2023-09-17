#include <iostream>

// add () toma dos enteros como parametros y devuelve el parametro de la suama 
// los valores de x e y estan determinados por la funcion de add ()

int add (int x,int y)
{
     return x + y ;
     
}
// main no toma parametros 

int main ()
{
     std::cout << add (4,5) << '\n';//los argumentos se pasan ala funccion add ()
     return 0;
}