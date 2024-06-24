#ifndef PRODUTOPERECIVEL_HPP
#define PRODUTOPERECIVEL_HPP

#include "Produto.hpp"
#include "Data.hpp"

class ProdutoPerecivel : public Produto {
public:
    ProdutoPerecivel(int id, const std::string& nome, const std::string& marca, double preco, const std::string& fornecedor, char setorArmazenamento, const Data& dataVencimento);

    Data getDataVencimento() const;
    bool estaProximoDoVencimento() const;

private:
    Data dataVencimento;
};

#endif // PRODUTOPERECIVEL_HPP
