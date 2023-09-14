#include <iostream>//para std :: std::cout 

void doprint  ()
{
     std::cout <<"en doprint()\n";
}

//definicion de la funcion main 
int main()
{
    
     std::cout <<"iniciando main ()\n";
     doprint (); //doprint ()llamado por primera vez
     doprint (); //doprint () llamado por segunda vez
     std::cout <<"finalizando main () \n";
     
     return 0;
    
    
    
    
}