#ifndef ESTOQUE_HPP
#define ESTOQUE_HPP

#include "Produto.hpp"
#include <vector>
#include <memory>
#include <algorithm>
#include <string>

class Estoque {
private:
    std::vector<std::unique_ptr<Produto>> produtos;
    int limiteMinimo;

public:
    Estoque(int limiteMinimo);

    void adicionarProduto(std::unique_ptr<Produto> produto);
    void removerProduto(const std::string& nome);
    Produto* buscarProduto(const std::string& nome);
    void listarProdutos() const;

    int getLimiteMinimo() const;

    const std::vector<std::unique_ptr<Produto>>& getProdutos() const;
};

#endif // ESTOQUE_HPP
