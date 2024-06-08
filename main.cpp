#include <iostream>
#include <vector>
#include <string>
#include "Produto.hpp"
#include "BancoDados.hpp"

using namespace std;

int main()
{
    int aux = 0;
    bool a;
    
    int id;
    string nome;
    string marca;
    double preco;
    string fornecedor; 
    char setorArmazenamento;

    vector<Produto> prodTeste;

/*
    while(aux != 2){
        cin >> id >> nome >> marca >> preco >> fornecedor >> setorArmazenamento;

        Produto *teste;
        teste = new Produto(id, nome, marca, preco, fornecedor, setorArmazenamento);

        prodTeste.push_back(*teste);
        delete teste;

        aux++;
    }
*/
    BancoDados *central;
    central = new BancoDados(prodTeste);

    //central->adicionaBanco();
    central->removeBanco(4);

    delete central;

    

    return 0;
}