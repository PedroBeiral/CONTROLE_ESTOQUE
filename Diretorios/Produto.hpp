#ifndef PRODUTO_HPP
#define PRODUTO_HPP

#include <string>

// Classe Produto representa um produto genérico no estoque
class Produto {
public:
    // Construtor que inicializa um produto com ID, nome, marca, preço, fornecedor e setor de armazenamento
    Produto(int id, const std::string& nome, const std::string& marca, double preco, const std::string& fornecedor, char setorArmazenamento);

    // Métodos de acesso (getters)
    int acessoID() const;
    std::string acessoNOME() const;
    std::string acessoMARCA() const;
    double acessoPRECO() const;
    std::string acessoFORNECEDOR() const;
    char acessoSETOR() const;

    // Métodos de modificação (setters)
    void setNome(const std::string& nome);
    void setMarca(const std::string& marca);
    void setPreco(double preco);
    void setFornecedor(const std::string& fornecedor);
    void setSetor(char setorArmazenamento);

private:
    int _id;  // Identificador do produto
    std::string _nome;  // Nome do produto
    std::string _marca;  // Marca do produto
    double _preco;  // Preço do produto
    std::string _fornecedor;  // Fornecedor do produto
    char _setorArmazenamento;  // Setor de armazenamento do produto
};

#endif // PRODUTO_HPP
