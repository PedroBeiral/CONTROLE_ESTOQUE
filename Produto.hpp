#ifndef PRODUTO_HPP
#define PRODUTO_HPP

#include <iostream>
#include <string>

using namespace std;

class Produto{

    public:
        Produto(int _id, string _nome, string _marca, double _preco, string _fornecedor, char _setorArmazenamento);
        void atualizarInfo(int id, auto info);
        int acessoID();
        string acessoNOME();
        string acessoMARCA();
        double acessoPRECO();
        string acessoFORNECEDOR();
        char acessoSETOR();
    
    private:
        int _id;
        string _nome;
        string _marca;
        double _preco;
        string _fornecedor; 
        char _setorArmazenamento;   
};

#endif