#include <fstream>

int main()
{
    std::ifstream arquivo_encontrado;
    std::ofstream arquivo_saida;

    // arquivo_encontrado.open("arquivo.txt");
    arquivo_saida.open("arquivo2.txt");
    // if(arquivo_encontrado.fail()){
    //     return 0;
    // }


    arquivo_saida<<"teste\nteste\n";


    // arquivo_encontrado.close();
    arquivo_saida.close();
    return 0;
}
