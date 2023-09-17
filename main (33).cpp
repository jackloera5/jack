//#include <iostream>
                              //mini test no compila 
//void multiply(int x,int y)
//{
    
//    return x * y;
    
//}

//int main()
//{
//    std::cout << multiply(4, 5) << '\n';
    
//    return 0;
    
//}
#include <iostream>

int multiply(int x, int y)    //lo unico que cambia para que este de una forma correcta es el void cambia a int
{
    return x * y;
}

int main()
{
    std::cout << multiply(4, 5) << '\n';
    
    return 0;
}

