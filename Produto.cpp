#include "Produto.hpp"

Produto::Produto(const std::string& nome, const std::string& sku, const std::string& descricao,
                 double precoCusto, double precoVenda, int quantidade, int lote,
                 const Date& dataRecebimento, const Date& dataFabricacao, const Date& dataValidade,
                 const std::string& categoria, const std::string& localizacao, const std::string& fornecedor,
                 const std::string& unidadeMedida, double pesoVolume, const std::string& notas, const std::string& imagem)
    : nome(nome), sku(sku), descricao(descricao), precoCusto(precoCusto), precoVenda(precoVenda),
      quantidade(quantidade), lote(lote), dataRecebimento(dataRecebimento), dataFabricacao(dataFabricacao),
      dataValidade(dataValidade), categoria(categoria), localizacao(localizacao), fornecedor(fornecedor),
      unidadeMedida(unidadeMedida), pesoVolume(pesoVolume), notas(notas), imagem(imagem) {
    if (precoCusto < 0 || precoVenda < 0 || quantidade < 0) {
        throw std::invalid_argument("Preço e quantidade devem ser não negativos.");
    }
}

// Implementação dos getters
std::string Produto::getNome() const { return nome; }
std::string Produto::getSku() const { return sku; }
std::string Produto::getDescricao() const { return descricao; }
double Produto::getPrecoCusto() const { return precoCusto; }
double Produto::getPrecoVenda() const { return precoVenda; }
int Produto::getQuantidade() const { return quantidade; }
int Produto::getLote() const { return lote; }
Date Produto::getDataRecebimento() const { return dataRecebimento; }
Date Produto::getDataFabricacao() const { return dataFabricacao; }
Date Produto::getDataValidade() const { return dataValidade; }
std::string Produto::getCategoria() const { return categoria; }
std::string Produto::getLocalizacao() const { return localizacao; }
std::string Produto::getFornecedor() const { return fornecedor; }
std::string Produto::getUnidadeMedida() const { return unidadeMedida; }
double Produto::getPesoVolume() const { return pesoVolume; }
std::string Produto::getNotas() const { return notas; }
std::string Produto::getImagem() const { return imagem; }

// Implementação dos setters
void Produto::setPrecoVenda(double preco) {
    if (preco < 0) {
        throw std::invalid_argument("Preço de venda deve ser não negativo.");
    }
    precoVenda = preco;
}

void Produto::setQuantidade(int quantidade) {
    if (quantidade < 0) {
        throw std::invalid_argument("Quantidade deve ser não negativa.");
    }
    this->quantidade = quantidade;
}

void Produto::adicionarEstoque(int qtd) {
    if (qtd < 0) {
        throw std::invalid_argument("Quantidade a adicionar deve ser não negativa.");
    }
    quantidade += qtd;
}

void Produto::removerEstoque(int qtd) {
    if (qtd < 0 || qtd > quantidade) {
        throw std::invalid_argument("Quantidade a remover inválida.");
    }
    quantidade -= qtd;
}
