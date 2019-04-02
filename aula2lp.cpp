#include <iostream>
 

int main()
{
    int numero1=0;
    int numero2=0;
    int numero3=0;

    std::cout <<"olá Adicione o primeiro número \n";
    std::cin >>numero1;
    std::cout <<"olá Adicione o segundo número \n";
    std::cin >>numero2;
    std::cout <<"olá Adicione o terceiro número \n";
    std::cin >>numero3;
    if (numero1<=numero2&&numero1<=numero3) {
        if(numero2<=numero3){
            std::cout <<numero1<<" "<<numero2<<" "<<numero3<<"\n";
        }else{
            std::cout <<numero1<<" "<<numero3<<" "<<numero3<<"\n";

        }
    }else if(numero2<=numero1&&numero2<=numero3) {
        if(numero1<=numero3){
            std::cout <<numero2<<" "<<numero1<<" "<<numero3<<"\n";
        }else{
            std::cout <<numero2<<" "<<numero3<<" "<<numero1<<"\n";

        }
    }else if(numero3<=numero1&&numero3<=numero2) {
        if(numero1<=numero2){
            std::cout <<numero3<<" "<<numero1<<" "<<numero2<<"\n";
        }else{
            std::cout <<numero3<<" "<<numero2<<" "<<numero1<<"\n";

        }
    }
    
    return 0;
}
