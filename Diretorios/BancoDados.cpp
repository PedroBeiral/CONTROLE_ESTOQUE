#include "BancoDados.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

// Construtor que inicializa o banco de dados com um nome de arquivo CSV
BancoDados::BancoDados(const std::string& nomeArquivo) : nomeArquivo(nomeArquivo) {}

// Adiciona um produto ao arquivo CSV
bool BancoDados::adicionaProduto(const Produto& produto) {
    std::ofstream arquivo(nomeArquivo, std::ios::app);
    if (!arquivo.is_open()) {
        std::cerr << "Não foi possível abrir o arquivo: " << nomeArquivo << std::endl;
        return false;
    }
    arquivo << produto.acessoID() << "," << produto.acessoNOME() << "," << produto.acessoMARCA() << ","
            << produto.acessoPRECO() << "," << produto.acessoFORNECEDOR() << "," << produto.acessoSETOR() << "\n";
    arquivo.close();
    return true;
}

// Remove um produto do arquivo CSV pelo ID
bool BancoDados::removeProduto(int idRemover) {
    std::ifstream arquivo(nomeArquivo);
    std::ofstream temp("temp.csv");
    std::string linha;
    bool encontrado = false;

    if (!arquivo.is_open() || !temp.is_open()) {
        std::cerr << "Não foi possível abrir o arquivo." << std::endl;
        return false;
    }

    // Copia todas as linhas, exceto a linha do produto a ser removido, para um arquivo temporário
    while (getline(arquivo, linha)) {
        std::istringstream ss(linha);
        std::string campo;
        getline(ss, campo, ',');
        if (std::stoi(campo) != idRemover) {
            temp << linha << "\n";
        } else {
            encontrado = true;
        }
    }

    arquivo.close();
    temp.close();

    if (encontrado) {
        std::remove(nomeArquivo.c_str());
        std::rename("temp.csv", nomeArquivo.c_str());
    } else {
        std::remove("temp.csv");
    }

    return encontrado;
}

// Busca um produto pelo ID no arquivo CSV
std::vector<Produto> BancoDados::buscaProduto(int idBuscar) {
    std::ifstream arquivo(nomeArquivo);
    std::string linha;
    std::vector<Produto> resultado;

    if (!arquivo.is_open()) {
        std::cerr << "Não foi possível abrir o arquivo: " << nomeArquivo << std::endl;
        return resultado;
    }

    // Percorre o arquivo CSV e busca o produto pelo ID
    while (getline(arquivo, linha)) {
        std::istringstream ss(linha);
        std::string campo;
        int id;
        std::string nome, marca, fornecedor;
        double preco;
        char setor;

        getline(ss, campo, ',');
        id = std::stoi(campo);
        if (id == idBuscar) {
            getline(ss, nome, ',');
            getline(ss, marca, ',');
            ss >> preco;
            ss.ignore(1); // Ignorar a vírgula
            getline(ss, fornecedor, ',');
            ss >> setor;

            Produto produto(id, nome, marca, preco, fornecedor, setor);
            resultado.push_back(produto);
        }
    }

    arquivo.close();
    return resultado;
}

// Carrega os dados do arquivo CSV para um vetor de strings
std::vector<std::string> BancoDados::carregaDados() {
    std::ifstream arquivo(nomeArquivo);
    std::string linha;
    std::vector<std::string> dados;

    if (!arquivo.is_open()) {
        std::cerr << "Não foi possível abrir o arquivo: " << nomeArquivo << std::endl;
        return dados;
    }

    // Carrega todas as linhas do arquivo CSV para um vetor de strings
    while (getline(arquivo, linha)) {
        dados.push_back(linha);
    }

    arquivo.close();
    return dados;
}

// Salva os dados do vetor de strings no arquivo CSV
bool BancoDados::salvaDados(const std::vector<std::string>& dados) {
    std::ofstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        std::cerr << "Não foi possível abrir o arquivo: " << nomeArquivo << std::endl;
        return false;
    }

    // Salva todas as linhas do vetor de strings no arquivo CSV
    for (const auto& linha : dados) {
        arquivo << linha << "\n";
    }

    arquivo.close();
    return true;
}
