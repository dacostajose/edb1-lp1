#include <iostream>

int main()
{
    int numero1=0;
    std::cin >>numero1;
    
    while(numero1!=0){
        std::cout<<numero1%10;
        numero1=numero1/10;
    }
    
    std::cout<<"\n";

    return 0;
}
 