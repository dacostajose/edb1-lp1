#include <iostream>
#include <cstdlib>

void quicksort(int* array, int inicio, int fim);
int particiona(int* array, int inicio, int fim);

int main()
{

    int tamanho_array=5000;
    int* array= new int[tamanho_array];
    int numeroteste=11;
    int indice=0;
    for (int i=0; i<tamanho_array; i++){
        array[i]=rand()%100;
    }
    quicksort(array, 0, tamanho_array-1);
    delete[] array;
    return 0;
}

void quicksort(int* array, int inicio, int fim){
    if (inicio<fim) {
        int poisicao_pivo=particiona(array, inicio, fim);
        quicksort(array, inicio, poisicao_pivo-1);
        quicksort(array, poisicao_pivo, fim);
    }
    
}

int particiona(int* array, int inicio, int fim){
    int poisicao_pivo=inicio;
    int pivo=array[poisicao_pivo];
    while(inicio<fim){
       while(array[inicio]<=pivo){
           inicio++;
       }
       while(array[fim]>pivo){
           fim--;
       }
       if(inicio<fim){
           int tmp=array[inicio];
           array[inicio]=array[fim];
           array[fim]= tmp;
       }
    }
    array[poisicao_pivo]= array[fim];
    array[fim]= pivo;
    
}
