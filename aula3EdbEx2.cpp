#include <iostream>
#include <cstdlib>
#include <chrono>

int main()
{

    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    int tamanho_array=145000;
    int* array= new int[tamanho_array];
    int numeroteste=0;

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
    

    for (int i=0; i<tamanho_array; i++){
        int posi1 = array[i];
        int numeromon=0;
        int aux1=i+1;
        int aux2=tamanho_array-1;
        while(aux1!=aux2){
            if(numeromon==numeroteste){
                end = std::chrono::system_clock::now();
                int elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds>
                (end-start).count();
                std::time_t end_time = std::chrono::system_clock::to_time_t(end);
                std::cout<< "Tempo de execução: " << elapsed_seconds << " milissegundos\n\n";
                std::cout<<"1"<<'\n'<<'\n';

                delete[] array;
                return 0;
            }else{
                if(numeromon<numeroteste){
                    aux1=aux1+1;
                }else{
                    aux2=aux2-1;
                }
                numeromon=posi1+array[aux1]+array[aux2];
            }
        }
                
    }
     end = std::chrono::system_clock::now();
    int elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds>
    (end-start).count();
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout<< "Tempo de execução: " << elapsed_seconds << " milissegundos\n\n";
    std::cout<<"0"<<'\n'<<'\n';
    delete[] array;

    return 0;
}
