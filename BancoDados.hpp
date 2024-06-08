#ifndef BANCODADOS_HPP
#define BANCODADOS_HPP

#include <iostream>
#include <vector>
#include <string>
#include "Produto.hpp"

using namespace std;

class BancoDados{

    public:
        BancoDados(vector<Produto> dados);
        bool adicionaBanco();
        bool removeBanco(int id_remover);
        //bool manipulaAtributos(int id, auto atributo);

    private:
        vector<Produto> _dados;    
};

#endif