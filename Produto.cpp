#include "Produto.hpp"

// Implementação do construtor da classe Produto
Produto::Produto(int id, const std::string& nome, const std::string& marca, double preco, const std::string& fornecedor, char setorArmazenamento)
    : _id(id), _nome(nome), _marca(marca), _preco(preco), _fornecedor(fornecedor), _setorArmazenamento(setorArmazenamento) {}

// Métodos de acesso (getters)
int Produto::acessoID() const {
    return _id;
}

std::string Produto::acessoNOME() const {
    return _nome;
}

std::string Produto::acessoMARCA() const {
    return _marca;
}

double Produto::acessoPRECO() const {
    return _preco;
}

std::string Produto::acessoFORNECEDOR() const {
    return _fornecedor;
}

char Produto::acessoSETOR() const {
    return _setorArmazenamento;
}

// Métodos de modificação (setters)
void Produto::setNome(const std::string& nome) {
    _nome = nome;
}

void Produto::setMarca(const std::string& marca) {
    _marca = marca;
}

void Produto::setPreco(double preco) {
    _preco = preco;
}

void Produto::setFornecedor(const std::string& fornecedor) {
    _fornecedor = fornecedor;
}

void Produto::setSetor(char setorArmazenamento) {
    _setorArmazenamento = setorArmazenamento;
}
