#include <iostream>
#include <cstdlib>
#include "vector.h"
//Busca binaria
void quicksort(int *array, int inicio, int fim);
int particiona(int *array, int inicio, int fim);

int main()
{
    char teste = 'a';

    return 0;
}

int binarySearch(int arr[], int inicio, int tamanho, int teste)
{
    if (tamanho >= inicio)
    {
        int mid = inicio + (tamanho - inicio) / 2;

        if (arr[mid] == teste)
        {
            return mid;
        }
        if (arr[mid] > teste)
        {
            return binarySearch(arr, inicio, mid - 1, teste);
        }
        else
        {
            return binarySearch(arr, mid + 1, tamanho, teste);
        }
    };
};

int at(int arr[], int position)
{
    return (arr[position]);
}

void quicksort(int *array, int inicio, int fim)
{
    if (inicio < fim)
    {
        int poisicao_pivo = particiona(array, inicio, fim);
        quicksort(array, inicio, poisicao_pivo - 1);
        quicksort(array, poisicao_pivo, fim);
    }
}

int particiona(int *array, int inicio, int fim)
{
    int poisicao_pivo = inicio;
    int pivo = array[poisicao_pivo];
    while (inicio < fim)
    {
        while (array[inicio] <= pivo)
        {
            inicio++;
        }
        while (array[fim] > pivo)
        {
            fim--;
        }
        if (inicio < fim)
        {
            int tmp = array[inicio];
            array[inicio] = array[fim];
            array[fim] = tmp;
        }
    }
    array[poisicao_pivo] = array[fim];
    array[fim] = pivo;
}

void print()
{
    int array[10];
    int arraySize = (sizeof(array) / sizeof(*array));
    for (int i = 0; i < arraySize; i++)
    {
        std::cout << array[i];
    }
}
int size()
{
}
bool empty()
{
}