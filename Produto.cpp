#include <iostream>
#include <string>
#include "Produto.hpp"
#include "BancoDados.hpp"

using namespace std;

Produto::Produto(int id, string nome, string marca, double preco, string fornecedor, char setorArmazenamento){
    this->_id = id;
    this->_nome = nome;
    this->_marca = marca;
    this->_preco = preco;
    this->_fornecedor = fornecedor;
    this->_setorArmazenamento = setorArmazenamento;
}

void Produto::atualizarInfo(int id, auto info){
    bool ver = manipulaAtributos(id, info);
    if(ver)
        cout << "Informacao do produto atualizada com exito!" << endl;
    else    
        cout << "Erro ao atualizar!" << endl;  
}

int Produto::acessoID(){
    return this->_id;
}

string Produto::acessoNOME(){
    return this->_nome;
}

string Produto::acessoMARCA(){
    return this->_marca;
}

double Produto::acessoPRECO(){
    return this->_preco;
}

string Produto::acessoFORNECEDOR(){
    return this->_fornecedor;
}

char Produto::acessoSETOR(){
    return this->_setorArmazenamento;
}