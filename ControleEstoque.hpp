#ifndef CONTROLEESTOQUE_HPP
#define CONTROLEESTOQUE_HPP

#include <string>
#include <vector>
#include "BancoDados.hpp"
#include "Produto.hpp"

class ControleEstoque {
public:
    ControleEstoque(const std::string& nomeArquivo);
    void adicionaProduto(const Produto& produto);
    void removeProduto(int id);
    void atualizaProduto(int id, const std::string& atributo, const std::string& novoValor);
    void exibeProduto(int id);
    std::vector<Produto> buscarTodosOsProdutos() const; // Adicionado método para buscar todos os produtos

private:
    BancoDados banco;
};

#endif // CONTROLEESTOQUE_HPP
