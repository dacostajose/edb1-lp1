#include <iostream>
#include <cstdlib>
#include <chrono>

int busca_binaria(int* array, int numeroteste, int inicio, int fim);

int main()
{

    int tamanho_array=5000;
    int* array= new int[tamanho_array];
    int numeroteste=11;
    int indice=0;
    for (int i=0; i<tamanho_array; i++){
        array[i]=rand()%100;

    }

    for(int i = 0; i < tamanho_array-1; i++){
        int posi1 = array[i];
        for(int j = i; j < tamanho_array; j++){
            int posi2=array[j];
            if(posi1<posi2){
                array[i]=posi2;
                array[j]=posi1;
            }
        }
        
    }
    

    indice=busca_binaria(array, numeroteste,  0, tamanho_array-1);
   
    std::cout<<indice<<'\n'<<'\n';
    delete[] array;

    return 0;
}

int busca_binaria(int* array, int numeroteste, int inicio, int fim){
    if(fim<inicio){
        std::cout<<"este caso1";
        return -1;
    }
    int meio=fim+(fim-inicio)/2;
    if(numeroteste == array[meio]){
        return meio;
    }else if(numeroteste > array[meio]){
       return busca_binaria(array, numeroteste, meio, fim-1);
    }else if(numeroteste < array[meio]){
       return busca_binaria(array, numeroteste, 0, meio-1);
    }
    std::cout<<"este caso2";

    return -1;
}
