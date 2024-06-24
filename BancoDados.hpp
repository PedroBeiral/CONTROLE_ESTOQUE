#ifndef BANCODADOS_HPP
#define BANCODADOS_HPP

#include <vector>
#include <string>
#include "Produto.hpp"

// Classe BancoDados gerencia operações de banco de dados para produtos
class BancoDados {
public:
    // Construtor que inicializa o banco de dados com um nome de arquivo CSV
    BancoDados(const std::string& nomeArquivo);

    // Adiciona um produto ao banco de dados
    bool adicionaProduto(const Produto& produto);

    // Remove um produto do banco de dados pelo ID
    bool removeProduto(int idRemover);

    // Busca um produto no banco de dados pelo ID
    std::vector<Produto> buscaProduto(int idBuscar);

private:
    std::string nomeArquivo; // Nome do arquivo CSV utilizado como banco de dados

    // Carrega os dados do arquivo CSV
    std::vector<std::string> carregaDados();

    // Salva os dados no arquivo CSV
    bool salvaDados(const std::vector<std::string>& dados);
};

#endif // BANCODADOS_HP
