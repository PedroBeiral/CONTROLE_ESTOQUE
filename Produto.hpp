#ifndef PRODUTO_HPP
#define PRODUTO_HPP

#include "Date.hpp"
#include <string>
#include <iostream>

class Produto {
protected:
    std::string nome;
    std::string sku;
    std::string descricao;
    double precoCusto;
    double precoVenda;
    int quantidade;
    int lote;
    Date dataRecebimento;
    Date dataFabricacao;
    Date dataValidade;
    std::string categoria;
    std::string localizacao;
    std::string fornecedor;
    std::string unidadeMedida;
    double pesoVolume;
    std::string notas;
    std::string imagem;

public:
    Produto(const std::string& nome, const std::string& sku, const std::string& descricao,
            double precoCusto, double precoVenda, int quantidade, int lote,
            const Date& dataRecebimento, const Date& dataFabricacao, const Date& dataValidade,
            const std::string& categoria, const std::string& localizacao, const std::string& fornecedor,
            const std::string& unidadeMedida, double pesoVolume, const std::string& notas, const std::string& imagem);
    virtual ~Produto() = default;

    // Getters
    std::string getNome() const;
    std::string getSku() const;
    std::string getDescricao() const;
    double getPrecoCusto() const;
    double getPrecoVenda() const;
    int getQuantidade() const;
    int getLote() const;
    Date getDataRecebimento() const;
    Date getDataFabricacao() const;
    Date getDataValidade() const;
    std::string getCategoria() const;
    std::string getLocalizacao() const;
    std::string getFornecedor() const;
    std::string getUnidadeMedida() const;
    double getPesoVolume() const;
    std::string getNotas() const;
    std::string getImagem() const;

    // Setters
    void setPrecoVenda(double preco);
    void setQuantidade(int quantidade);

    virtual void mostrarDetalhes() const = 0;

    void adicionarEstoque(int qtd);
    void removerEstoque(int qtd);
};

#endif // PRODUTO_HPP

