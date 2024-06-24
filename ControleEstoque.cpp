#include "ControleEstoque.hpp"
#include <iostream>

// Construtor que inicializa o controle de estoque com o nome do arquivo de banco de dados
ControleEstoque::ControleEstoque(const std::string& nomeArquivo) : banco(nomeArquivo) {}

// Adiciona um produto ao estoque
void ControleEstoque::adicionaProduto(const Produto& produto) {
    if (banco.adicionaProduto(produto)) {
        std::cout << "Produto adicionado com sucesso!" << std::endl;
    } else {
        std::cout << "Erro ao adicionar o produto." << std::endl;
    }
}

// Remove um produto do estoque pelo ID
void ControleEstoque::removeProduto(int id) {
    if (banco.removeProduto(id)) {
        std::cout << "Produto removido com sucesso!" << std::endl;
    } else {
        std::cout << "Erro ao remover o produto." << std::endl;
    }
}

// Atualiza um produto no estoque pelo ID e atributo
void ControleEstoque::atualizaProduto(int id, const std::string& atributo, const std::string& novoValor) {
    std::vector<Produto> produtos = banco.buscaProduto(id);
    if (!produtos.empty()) {
        Produto produto = produtos[0]; // Considerando que o ID é único e que produtos[0] é o produto correto

        if (atributo == "nome") {
            produto.setNome(novoValor);
        } else if (atributo == "marca") {
            produto.setMarca(novoValor);
        } else if (atributo == "preco") {
            produto.setPreco(std::stod(novoValor));
        } else if (atributo == "setor") {
            produto.setSetor(novoValor[0]);
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

// Exibe as informações de um produto pelo ID
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

// Busca todos os produtos no banco de dados
std::vector<Produto> ControleEstoque::buscarTodosOsProdutos() const {
    return banco.carregaDados();
}
