#include <iostream>
#include <fstream>
#include <string>

void criar_imagem(int largura, int altura);
int mover_baixo(int posicao_atual, int movimentos, int skeepheader, bool levantado, int largura, int altura);
int mover_cima(int posicao_atual, int movimentos, int skeepheader, bool levantado, int largura, int altura);
int mover_esquerda(int posicao_atual, int movimentos, int skeepheader, bool levantado, int largura, int altura);
int mover_direita(int posicao_atual, int movimentos, int skeepheader, bool levantado, int largura, int altura);

int main()
{
    int largura = 0;
    int altura = 0;
    int quantidade_comandos = 0;
    int posicao_atual = 27;
    bool levantado = true;
    int skeepheader;
    std::ifstream comandos;
    comandos.open("arquivos_entrada/exemplo1.txt");
    char output[100];
    if (!comandos)
    {
        std::cout << "ocorreu um erro ao abrir o arquivo";
        comandos.close();
        return 0;
    }

    std::string line;
    comandos >> largura;
    comandos >> altura;
    comandos >> quantidade_comandos;
    //std::cout << largura << '\n'
    //        << altura << '\n';

    criar_imagem(largura, altura);
    skeepheader = (std::to_string(largura).length()) + (std::to_string(altura).length());

    for (int i = 0; i < quantidade_comandos; i++)
    {

        comandos >> output;
        std::cout << output << '\n';
        //std::cout << "saída " << output << '\n';

        //std::cout << "saída2 " << output << '\n';
        if (output[0] == 's')
        {
            levantado = true;
        }
        else if (output[0] == 'a')
        {
            levantado = false;
        }
        else if (output[0] == 'c')
        {
            //std::cout << "chamou cima" << '\n';
            posicao_atual = mover_cima(posicao_atual, 200, skeepheader, levantado, largura, altura);
        }
        else if (output[0] == 'b')
        {
            //std::cout << "\n valor: "
            //          << "\n \n\n";
            posicao_atual = mover_baixo(posicao_atual, 400, skeepheader, levantado, largura, altura);
            //std::cout << "posição atual" << posicao_atual << '\n';
        }
        else if (output[0] == 'e')
        {
            //std::cout << "chamou esquerda" << '\n';
            posicao_atual = mover_esquerda(posicao_atual, 200, skeepheader, levantado, largura, altura);
        }
        else if (output[0] == 'd')
        {
            //std::cout << "chamou direita" << '\n';

            posicao_atual = mover_direita(posicao_atual, 200, skeepheader, levantado, largura, altura);
        }
        else
        {
            //std::cout << "Comando invalido";
        }
    }

    comandos.close();
    return 0;
}

void criar_imagem(int largura, int altura)
{
    std::cout << "Chegou aqui\n";
    std::ofstream imagem_saida;
    imagem_saida.open("imagem1.pbm");
    imagem_saida << "P1\n";
    imagem_saida << "#José da Costa Filho\n";
    imagem_saida << largura << " " << altura << '\n';
    for (int i = 0; i < largura * altura; i++)
    {
        imagem_saida << 0;
    }
    imagem_saida.close();
}

int mover_baixo(int posicao_atual, int movimentos, int skeepheader, bool levantado, int largura, int altura)
{
    //std::cout << posicao_atual;
    std::ofstream imagem_saida("imagem1.pbm", std::ios::out | std::ios::in);
    imagem_saida.seekp(skeepheader + 27);
    if (levantado == 0)
    {
        for (int i = 0; i < movimentos; i++)
        {
            if ((posicao_atual + largura) < (altura * largura))
            {
                posicao_atual = posicao_atual + largura;
            }
        }
    }
    else
    {
        for (int i = 0; i < movimentos; i++)
        {
            if ((posicao_atual + largura) < (altura * largura))
            {
                posicao_atual = posicao_atual + largura;
                imagem_saida.seekp(posicao_atual - 1);
                imagem_saida << 1;
            }
        }
    }

    imagem_saida.close();
    return posicao_atual;
}
int mover_cima(int posicao_atual, int movimentos, int skeepheader, bool levantado, int largura, int altura)
{

    std::ofstream imagem_saida("imagem1.pbm", std::ios::out | std::ios::in);
    imagem_saida.seekp(skeepheader + 27);
    if (levantado == 0)
    {
        for (int i = 0; i < movimentos; i++)
        {
            if ((posicao_atual - largura) > 27)
            {
                posicao_atual = posicao_atual - largura;
            }
        }
    }
    else
    {
        for (int i = 0; i < movimentos; i++)
        {
            if ((posicao_atual - largura) > 27)
            {
                posicao_atual = posicao_atual - largura;
                imagem_saida.seekp(posicao_atual - 1);
                imagem_saida << 1;
            }
        }
    }

    imagem_saida.close();
    return posicao_atual;
}
int mover_esquerda(int posicao_atual, int movimentos, int skeepheader, bool levantado, int largura, int altura)
{
    std::ofstream imagem_saida("imagem1.pbm", std::ios::out | std::ios::in);
    imagem_saida.seekp(skeepheader + 27);
    if (levantado == 0)
    {
        for (int i = 0; i < movimentos; i++)
        {
            if ((posicao_atual - 1) > 27)
            {
                posicao_atual = posicao_atual - 1;
            }
        }
    }
    else
    {
        for (int i = 0; i < movimentos; i++)
        {
            if ((posicao_atual - 1) > 27)
            {
                posicao_atual = posicao_atual - 1;
                imagem_saida.seekp(posicao_atual - 1);
                imagem_saida << 1;
            }
        }
    }

    imagem_saida.close();
    return posicao_atual;
}
int mover_direita(int posicao_atual, int movimentos, int skeepheader, bool levantado, int largura, int altura)
{
    std::ofstream imagem_saida("imagem1.pbm", std::ios::out | std::ios::in);
    imagem_saida.seekp(skeepheader + 27);
    if (levantado == 0)
    {
        for (int i = 0; i < movimentos; i++)
        {
            if ((posicao_atual + altura) < (altura * largura))
            {
                posicao_atual = posicao_atual + 1;
            }
        }
    }
    else
    {
        for (int i = 0; i < movimentos; i++)
        {
            if ((posicao_atual + altura) < (altura * largura))
            {
                posicao_atual = posicao_atual + 1;
                imagem_saida.seekp(posicao_atual - 1);
                imagem_saida << 1;
            }
        }
    }

    imagem_saida.close();
    return posicao_atual;
}
