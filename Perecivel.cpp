#include "Perecivel.hpp"

Perecivel::Perecivel(const std::string& nome, const std::string& sku, const std::string& descricao,
                       double precoCusto, double precoVenda, int quantidade, int lote,
                       const Date& dataRecebimento, const Date& dataFabricacao, const Date& dataValidade,
                       const std::string& categoria, const std::string& localizacao, const std::string& fornecedor,
                       const std::string& unidadeMedida, double pesoVolume, const std::string& notas, const std::string& imagem)
    : Produto(nome, sku, descricao, precoCusto, precoVenda, quantidade, lote, dataRecebimento, dataFabricacao, dataValidade, categoria, localizacao, fornecedor, unidadeMedida, pesoVolume, notas, imagem) {}

void Perecivel::mostrarDetalhes() const {
    std::cout << "Produto Perecível: " << nome << ", Preço: " << precoVenda
              << ", Quantidade: " << quantidade << ", Lote: " << lote
              << ", Recebido em: " << dataRecebimento.toString()
              << ", Fabricado em: " << dataFabricacao.toString()
              << ", Validade: " << dataValidade.toString() << std::endl;
}
