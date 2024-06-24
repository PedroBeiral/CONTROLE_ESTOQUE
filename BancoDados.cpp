#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cerrno>
#include <cstring>
#include "Produto.hpp"
#include "BancoDados.hpp"

BancoDados::BancoDados(const std::string& nomeArquivo) : nomeArquivo(nomeArquivo) {}

bool BancoDados::adicionaProduto(const Produto& produto) {
    std::ofstream arquivo(nomeArquivo, std::ios::out | std::ios::app);
    if (!arquivo.is_open()) {
        std::cerr << "Não foi possível abrir o arquivo: " << nomeArquivo << std::endl;
        return false;
    } else {
        arquivo << produto.acessoID() << "," 
                << produto.acessoNOME() << "," 
                << produto.acessoMARCA() << "," 
                << produto.acessoPRECO() << "," 
                << produto.acessoSETOR() << "," 
                << produto.acessoFORNECEDOR() << std::endl;
        arquivo.close();
        return true;
    }
}

bool BancoDados::removeProduto(int idRemover) {
    std::string linha;
    bool encontrou = false;

    std::ifstream arquivo(nomeArquivo);
    std::ofstream tempArq("Auxiliar.csv");

    if (!arquivo.is_open() || !tempArq.is_open()) {
        std::cerr << "Não foi possível abrir o arquivo" << std::endl;
        return false;
    } else {
        while (getline(arquivo, linha)) {
            std::stringstream ss(linha);
            std::string idStr;
            getline(ss, idStr, ',');
            int id = std::stoi(idStr);

            if (idRemover != id) {
                tempArq << linha << std::endl;
            } else {
                encontrou = true;
            }
        }
        arquivo.close();
        tempArq.close();

        if (encontrou) {
            if (rename("Auxiliar.csv", nomeArquivo.c_str()) != 0) {
                std::cerr << "Erro ao renomear o arquivo: " << std::strerror(errno) << std::endl;
                return false;
            } else {
                std::cout << "Produto removido com sucesso!" << std::endl;
            }
        } else {
            remove("Auxiliar.csv");
            std::cout << "Esse produto não está no estoque!" << std::endl;
            return false;
        }
    }
    return true;
}

std::vector<Produto> BancoDados::buscaProduto(int idBuscar) {
    std::vector<Produto> resultado;
    std::string linha;

    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        std::cerr << "Não foi possível abrir o arquivo: " << nomeArquivo << std::endl;
        return resultado;
    } else {
        while (getline(arquivo, linha)) {
            std::stringstream ss(linha);
            std::string idStr;
            getline(ss, idStr, ',');
            int id = std::stoi(idStr);

            if (idBuscar == id) {
                std::string nome, marca, preco, setor, fornecedor;
                getline(ss, nome, ',');
                getline(ss, marca, ',');
                getline(ss, preco, ',');
                getline(ss, setor, ',');
                getline(ss, fornecedor, ',');

                Produto produto(id, nome, marca, std::stof(preco), setor, fornecedor);
                resultado.push_back(produto);
            }
        }
        arquivo.close();
    }
    return resultado;
}


