#ifndef CONTROLEESTOQUE_HPP
#define CONTROLEESTOQUE_HPP

#include <string>
#include <vector>
#include "BancoDados.hpp"
#include "Produto.hpp"

// Classe ControleEstoque gerencia as operações de controle de estoque
class ControleEstoque {
public:
    // Construtor que inicializa o controle de estoque com o nome do arquivo de banco de dados
    ControleEstoque(const std::string& nomeArquivo);

    // Adiciona um produto ao estoque
    void adicionaProduto(const Produto& produto);

    // Remove um produto do estoque pelo ID
    void removeProduto(int id);

    // Atualiza um produto no estoque pelo ID e atributo
    void atualizaProduto(int id, const std::string& atributo, const std::string& novoValor);

    // Exibe as informações de um produto pelo ID
    void exibeProduto(int id);

    // Busca todos os produtos no banco de dados
    std::vector<Produto> buscarTodosOsProdutos() const;

private:
    BancoDados banco; // Instância de BancoDados para gerenciar as operações de banco de dados
};

#endif // CONTROLEESTOQUE_HPP
