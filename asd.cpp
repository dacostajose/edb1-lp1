#include <iostream>
#include <cstdlib>

void func (char valor){
    for(int i;i<10;i++){
        std::cout<<valor<<'\n';
    }

}
int main()
{
    char teste='a';
    func(teste);
   

    return 0;
}
