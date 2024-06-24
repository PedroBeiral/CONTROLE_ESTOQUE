#include "ProdutoPerecivel.hpp"

ProdutoPerecivel::ProdutoPerecivel(int id, const std::string& nome, const std::string& marca, double preco, const std::string& fornecedor, char setorArmazenamento, const Data& dataVencimento)
    : Produto(id, nome, marca, preco, fornecedor, setorArmazenamento), dataVencimento(dataVencimento) {}

Data ProdutoPerecivel::getDataVencimento() const {
    return dataVencimento;
}

bool ProdutoPerecivel::estaProximoDoVencimento() const {
    return dataVencimento.estaProximoDoVencimento();
}
