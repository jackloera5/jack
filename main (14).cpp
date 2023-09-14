#include <iostream>// para std :: std::cout 

void doB()

{
     std::cout<<"en dob()\n";
     
    
}
void doA()
{
    std::cout<<"iniciando doAm ()\n";
    doB();
    std::cout<<"Finalizando doA()\n";
    
}

//Definicion de la funcion main()
int main ()
{
     std::cout<<"iniciando main ()\n";
     doA();
     std::cout<<"Finalizando main ()\n";
     
     return 0;
     
}