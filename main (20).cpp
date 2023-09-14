#include <iostream>
//void significa que la funcion no devuelve un valor ala persona que llama 
void returnNothing ()
{
     std::cout <<"hola"<<'\n';
     // esta funcion no dcevuelve un valor , por lo que no nesesita una declaracion de funcion 
}

int main()
{
     returnNothing (); //bien se lalama ala funcion de returnNothing(),no se devuelve ningun valor 
     //std::cout << returnNothing();//esta linea no se compilara debera comentarla para continuar
     return 0;
     
    
    
    
}