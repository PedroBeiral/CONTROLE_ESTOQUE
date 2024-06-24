#ifndef BANCODADOS_HPP
#define BANCODADOS_HPP

#include <iostream>
#include <vector>
#include <string>
#include "Produto.hpp"

class BancoDados {
public:
    BancoDados(const std::string& nomeArquivo);
    bool adicionaProduto(const Produto& produto);
    bool removeProduto(int idRemover);
    std::vector<Produto> buscaProduto(int idBuscar);

private:
    std::string nomeArquivo;
    std::vector<std::string> carregaDados();
    bool salvaDados(const std::vector<std::string>& dados);
};

#endif // BANCODADOS_HPP
