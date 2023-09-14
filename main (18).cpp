#include<iostream>

//int es el tipo de retorno 
//un tipo de retorno de int significa que la funcion devolvera algun valor entero ala persona que llama el valor (el valor espesifico)

int returnCinco()
{
     //la declaracion de retorno indica el valor espesifico que se devolvera 
     return 5;//devuelve el valor espesifico 5 ala persona que llama 
}

int main ()
{
     std:: cout << returnCinco () <<'\n'; //imprime 5 
     std :: cout <<returnCinco () +2<<'\n';//imprime 7
     returnCinco ();//bien se debuelve el valor 5, pero se ignora ya que main()no ase nada con el 
     return 0;
}