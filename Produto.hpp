#ifndef PRODUTO_HPP
#define PRODUTO_HPP

#include <string>

class Produto {
public:
    Produto(int id, const std::string& nome, const std::string& marca, double preco, const std::string& fornecedor, char setorArmazenamento);

    int acessoID() const;
    std::string acessoNOME() const;
    std::string acessoMARCA() const;
    double acessoPRECO() const;
    std::string acessoFORNECEDOR() const;
    char acessoSETOR() const;

    void setNome(const std::string& nome);
    void setMarca(const std::string& marca);
    void setPreco(double preco);
    void setFornecedor(const std::string& fornecedor);
    void setSetor(char setorArmazenamento);

private:
    int _id;
    std::string _nome;
    std::string _marca;
    double _preco;
    std::string _fornecedor;
    char _setorArmazenamento;
};

#endif // PRODUTO_HPP
