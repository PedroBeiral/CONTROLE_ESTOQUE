#ifndef PRODUTOPERECIVEL_HPP
#define PRODUTOPERECIVEL_HPP

#include "Produto.hpp"
#include "Data.hpp"

// Classe ProdutoPerecivel representa um produto perecível no estoque
class ProdutoPerecivel : public Produto {
public:
    // Construtor que inicializa um produto perecível com data de vencimento
    ProdutoPerecivel(int id, const std::string& nome, const std::string& marca, double preco, const std::string& fornecedor, char setorArmazenamento, const std::string& dataVencimento);

    // Retorna a data de vencimento do produto perecível
    Data getDataVencimento() const;

    // Verifica se o produto está próximo do vencimento
    bool estaProximoDoVencimento() const;

private:
    Data dataVencimento; // Data de vencimento do produto perecível
};

#endif // PRODUTOPERECIVEL_HPP
