#include<iostream>//std::std::cout 

void doB()
{
    std::cout<<"en doB()\n";
    
}
void doA()
{
    std::cout<<"enn doA()\n";
    doB();
    
}

//definicion de la funcion main()
int main()
{
    std::cout<<"iniciando main()\n";
    doA();
    doB();
    std::cout<<"Finalizando main()\n";
    return 0;
    
}