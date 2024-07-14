#ifndef PERECIVEL_HPP
#define PERECIVEL_HPP

#include "Produto.hpp"

class Perecivel : public Produto {
public:
    Perecivel(const std::string& nome, const std::string& sku, const std::string& descricao,
               double precoCusto, double precoVenda, int quantidade, int lote,
               const Date& dataRecebimento, const Date& dataFabricacao, const Date& dataValidade,
               const std::string& categoria, const std::string& localizacao, const std::string& fornecedor,
               const std::string& unidadeMedida, double pesoVolume, const std::string& notas, const std::string& imagem);

    void mostrarDetalhes() const override;
};

#endif // PERECIVEL_HPP
