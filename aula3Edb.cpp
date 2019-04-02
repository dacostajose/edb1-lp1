#include <iostream>
#include <cstdlib>
#include <chrono>

int main()
{
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    int tamanho_array=75000;
    int* array= new int[tamanho_array];
    int numeroteste=10;

    for (int i=0; i<tamanho_array; i++){
        array[i]=rand()%100;

    }

    for (int i=0; i<tamanho_array-2; i++){
        int posi1 = array[i];
        for(int j = i+1; j < tamanho_array-1; j++){
            int posi2=array[j];
             for(int k = j+2; k < tamanho_array; k++){
                    int posi3=array[k];
                    if(posi1+posi2+posi3==numeroteste){
                        end = std::chrono::system_clock::now();
                        int elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>
                                                (end-start).count();
                        std::time_t end_time = std::chrono::system_clock::to_time_t(end);

                        std::cout<< "Tempo de execução: " << elapsed_seconds << " segundos\n\n";
                        std::cout<<'0'<<'\n'<<'\n';
                        delete[] array;

                        return 0;
                    }
                }
        }
        
    }


    std::cout<<'1'<<'\n';
    end = std::chrono::system_clock::now();
    int elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>
                             (end-start).count();
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds << "s\n";
     std::cout<<"Fim"<<'\n';

    delete[] array;

    return 0;
}
