#include <iostream>
#include <cstdlib>
struct Pessoa
{
    char nome[50];
};
struct Item
{
    char nome[50];
    bool emprestado;
};
struct Emprestimo
{
    int pessoaEmp;
    int itemEmp;
};

int main()
{

    Pessoa* pessoas= new Pessoa[100];
    Item* itens= new Item[100];
    Emprestimo* emprestimos= new Emprestimo[100];

    int pessoaIndex=0;
    int ItemIndex=0;
    char opcao;
    while(opcao!='s'){
        std::cout<<"insira a para Cadastrar Itens"<<'\n'<<"insira b para Cadastrar Pessoas"<<'\n'<<"insira c para Realizar Empréstimo"<<'\n'<<"insira d para Realizar Devolução"<<'\n'<<"insira e para Listar Todos os Itens"<<'\n'<<"insira f para Listar Itens emprestados"<<'\n'<<"insira g para Listar todas pessoas"<<'\n'<<"insira s para sair"<<'\n';
        std::cin>>opcao;
        if(opcao=='a'){
            std::cout<<"Cadastrar Itens"<<'\n';
            if(ItemIndex<100){
                std::cout<<"Adicionar nome"<<'\n';
                std::cin.get(itens[ItemIndex].nome, 50);
                std::cout<<"Adicionar nome insira 0 para true e 1 para false"<<'\n';
                int aux1=0;
                if(aux1==0){
                    itens[ItemIndex].emprestado=true;
                }else{
                    itens[ItemIndex].emprestado=true;
                }
            }else{
                std::cout<<"Atingiu o limite de itens"<<'\n';
            }
        }else if(opcao=='b'){
            std::cout<<"Cadastrar Pessoas"<<'\n';
            if(pessoaIndex<100){
                std::cout<<"Adicionar nome"<<'\n';
                std::cin.get(pessoas[pessoaIndex].nome, 50);
            }else{
                std::cout<<"Atingiu o limite "<<'\n';
            }
        }else if(opcao=='c'){
            
        }else if(opcao=='d'){
            std::cout<<'d';
        }else if(opcao=='e'){
            std::cout<<"Listar todos os itens"<<'\n';
            for(int i=0; i<ItemIndex; i++){
                std::cout<<"Nome do item"<<itens[i].nome<<'\n';
                (itens[i].emprestado)?(std::cout<<"O item esta emprestado"<<'\n'):(std::cout<<"O item esta disponivel"<<'\n');
            }
        }else if(opcao=='f'){
            std::cout<<'f';
        }else if(opcao=='g'){
            std::cout<<'g';
        }else{
             std::cout<<"insira algo valido"<<'\n';
        }
    
    }
    
    delete[] pessoas;
    delete[] itens;
    return 0;
}
