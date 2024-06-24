#include "ControleEstoque.hpp"
#include <iostream>

ControleEstoque::ControleEstoque(const std::string& nomeArquivo) : banco(nomeArquivo) {}

void ControleEstoque::adicionaProduto(const Produto& produto) {
    if (banco.adicionaProduto(produto)) {
        std::cout << "Produto adicionado com sucesso!" << std::endl;
    } else {
        std::cout << "Erro ao adicionar o produto." << std::endl;
    }
}

void ControleEstoque::removeProduto(int id) {
    if (banco.removeProduto(id)) {
        std::cout << "Produto removido com sucesso!" << std::endl;
    } else {
        std::cout << "Erro ao remover o produto." << std::endl;
    }
}

void ControleEstoque::atualizaProduto(int id, const std::string& atributo, const std::string& novoValor) {
    std::vector<Produto> produtos = banco.buscaProduto(id);
    if (!produtos.empty()) {
        Produto produto = produtos[0]; // Considerando que o ID é único e que produtos[0] é o produto correto

        if (atributo == "nome") {
            produto.setNome(novoValor);
        } else if (atributo == "marca") {
            produto.setMarca(novoValor);
        } else if (atributo == "preco") {
            produto.setPreco(std::stof(novoValor));
        } else if (atributo == "setor") {
            produto.setSetor(novoValor);
        } else if (atributo == "fornecedor") {
            produto.setFornecedor(novoValor);
        } else {
            std::cout << "Atributo inválido!" << std::endl;
            return;
        }

        banco.removeProduto(id);
        banco.adicionaProduto(produto);
        std::cout << "Produto atualizado com sucesso!" << std::endl;
    } else {
        std::cout << "Produto não encontrado." << std::endl;
    }
}

void ControleEstoque::exibeProduto(int id) {
    std::vector<Produto> produtos = banco.buscaProduto(id);
    if (!produtos.empty()) {
        Produto produto = produtos[0];
        std::cout << "Produto encontrado:" << std::endl;
        std::cout << "ID: " << produto.acessoID() << std::endl;
        std::cout << "Nome: " << produto.acessoNOME() << std::endl;
        std::cout << "Marca: " << produto.acessoMARCA() << std::endl;
        std::cout << "Preço: " << produto.acessoPRECO() << std::endl;
        std::cout << "Setor: " << produto.acessoSETOR() << std::endl;
        std::cout << "Fornecedor: " << produto.acessoFORNECEDOR() << std::endl;
    } else {
        std::cout << "Produto não encontrado." << std::endl;
    }
}
