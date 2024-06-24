#include "ProdutoPerecivel.hpp"

// Construtor que inicializa um produto perecível com data de vencimento
ProdutoPerecivel::ProdutoPerecivel(int id, const std::string& nome, const std::string& marca, double preco, const std::string& fornecedor, char setorArmazenamento, const Data& dataVencimento)
    : Produto(id, nome, marca, preco, fornecedor, setorArmazenamento), dataVencimento(dataVencimento) {}

// Retorna a data de vencimento do produto perecível
Data ProdutoPerecivel::getDataVencimento() const {
    return dataVencimento;
}

// Verifica se o produto está próximo do vencimento
bool ProdutoPerecivel::estaProximoDoVencimento() const {
    return dataVencimento.estaProximoDoVencimento();
}
