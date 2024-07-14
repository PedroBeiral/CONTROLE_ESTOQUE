#include "Estoque.hpp"
#include <iostream>

Estoque::Estoque(int limiteMinimo) : limiteMinimo(limiteMinimo) {}

void Estoque::adicionarProduto(std::unique_ptr<Produto> produto) {
    produtos.push_back(std::move(produto));
}

void Estoque::removerProduto(const std::string& nome) {
    auto it = std::remove_if(produtos.begin(), produtos.end(),
                             [&nome](const std::unique_ptr<Produto>& produto) {
                                 return produto->getNome() == nome;
                             });
    if (it != produtos.end()) {
        produtos.erase(it, produtos.end());
    } else {
        throw std::invalid_argument("Produto não encontrado.");
    }
}

Produto* Estoque::buscarProduto(const std::string& nome) {
    for (const auto& produto : produtos) {
        if (produto->getNome() == nome) {
            return produto.get();
        }
    }
    return nullptr;
}

void Estoque::listarProdutos() const {
    for (const auto& produto : produtos) {
        produto->mostrarDetalhes();
    }
}

int Estoque::getLimiteMinimo() const {
    return limiteMinimo;
}

const std::vector<std::unique_ptr<Produto>>& Estoque::getProdutos() const {
    return produtos;
}
