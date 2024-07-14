#include "CSVManager.hpp"
#include "Perecivel.hpp"
#include "NaoPerecivel.hpp"
#include <fstream>
#include <sstream>

void CSVManager::carregarProdutos(const std::string& filename, Estoque& estoque) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Não foi possível abrir o arquivo.");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string tipo, nome, sku, descricao, categoria, localizacao, fornecedor, unidadeMedida, notas, imagem, dataRecebimentoStr, dataFabricacaoStr, dataValidadeStr;
        double precoCusto, precoVenda;
        int quantidade, lote;
        double pesoVolume;

        std::getline(ss, tipo, ',');
        std::getline(ss, nome, ',');
        std::getline(ss, sku, ',');
        std::getline(ss, descricao, ',');
        ss >> precoCusto;
        ss.ignore();
        ss >> precoVenda;
        ss.ignore();
        ss >> quantidade;
        ss.ignore();
        ss >> lote;
        ss.ignore();
        std::getline(ss, dataRecebimentoStr, ',');
        std::getline(ss, dataFabricacaoStr, ',');
        std::getline(ss, dataValidadeStr, ',');
        std::getline(ss, categoria, ',');
        std::getline(ss, localizacao, ',');
        std::getline(ss, fornecedor, ',');
        std::getline(ss, unidadeMedida, ',');
        ss >> pesoVolume;
        ss.ignore();
        std::getline(ss, notas, ',');
        std::getline(ss, imagem, ',');

        Date dataRecebimento(dataRecebimentoStr);
        Date dataFabricacao(dataFabricacaoStr);
        Date dataValidade(dataValidadeStr);

        if (tipo == "Perecivel") {
            auto produto = std::make_unique<Perecivel>(nome, sku, descricao, precoCusto, precoVenda, quantidade, lote, dataRecebimento, dataFabricacao, dataValidade, categoria, localizacao, fornecedor, unidadeMedida, pesoVolume, notas, imagem);
            estoque.adicionarProduto(std::move(produto));
        } else if (tipo == "NaoPerecivel") {
            auto produto = std::make_unique<NaoPerecivel>(nome, sku, descricao, precoCusto, precoVenda, quantidade, lote, dataRecebimento, dataFabricacao, dataValidade, categoria, localizacao, fornecedor, unidadeMedida, pesoVolume, notas, imagem);
            estoque.adicionarProduto(std::move(produto));
        }
    }
    file.close();
}

void CSVManager::salvarProdutos(const std::string& filename, const Estoque& estoque) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Não foi possível abrir o arquivo.");
    }

    for (const auto& produto : estoque.getProdutos()) {
        file << (dynamic_cast<Perecivel*>(produto.get()) ? "Perecivel" : "NaoPerecivel") << ','
             << produto->getNome() << ','
             << produto->getSku() << ','
             << produto->getDescricao() << ','
             << produto->getPrecoCusto() << ','
             << produto->getPrecoVenda() << ','
             << produto->getQuantidade() << ','
             << produto->getLote() << ','
             << produto->getDataRecebimento().toString() << ','
             << produto->getDataFabricacao().toString() << ','
             << produto->getDataValidade().toString() << ','
             << produto->getCategoria() << ','
             << produto->getLocalizacao() << ','
             << produto->getFornecedor() << ','
             << produto->getUnidadeMedida() << ','
             << produto->getPesoVolume() << ','
             << produto->getNotas() << ','
             << produto->getImagem() << '\n';
    }
    file.close();
}

void CSVManager::carregarMovimentacoes(const std::string& filename, Historico& historico) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Não foi possível abrir o arquivo.");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string dataStr, tipo, sku, usuario;
        int quantidade;

        std::getline(ss, dataStr, ',');
        std::getline(ss, tipo, ',');
        std::getline(ss, sku, ',');
        ss >> quantidade;
        ss.ignore();
        std::getline(ss, usuario, ',');

        // Remover a variável 'data' pois não está sendo utilizada
        // std::time_t data = std::stoll(dataStr);
        historico.adicionarRegistro(tipo, "SKU: " + sku + ", Quantidade: " + std::to_string(quantidade) + ", Usuário: " + usuario);
    }
    file.close();
}

void CSVManager::salvarMovimentacoes(const std::string& filename, const Historico& historico) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Não foi possível abrir o arquivo.");
    }

    for (const auto& registro : historico.getRegistros()) {
        file << registro.timestamp << ','
             << registro.acao << ','
             << registro.detalhes << '\n';
    }
    file.close();
}

void CSVManager::carregarUsuarios(const std::string& filename, std::vector<Usuario>& usuarios) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Não foi possível abrir o arquivo.");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string nome, senha;
        bool administrador;

        std::getline(ss, nome, ',');
        std::getline(ss, senha, ',');
        ss >> administrador;

        usuarios.emplace_back(nome, senha, administrador);
    }
    file.close();
}

void CSVManager::salvarUsuarios(const std::string& filename, const std::vector<Usuario>& usuarios) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Não foi possível abrir o arquivo.");
    }

    for (const auto& usuario : usuarios) {
        file << usuario.getNome() << ','
             << usuario.getSenha() << ','
             << usuario.isAdmin() << '\n';
    }
    file.close();
}

void CSVManager::carregarHistorico(const std::string& filename, Historico& historico) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Não foi possível abrir o arquivo.");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string dataStr, acao, detalhes;

        std::getline(ss, dataStr, ',');
        std::getline(ss, acao, ',');
        std::getline(ss, detalhes, ',');

        // Remover a variável 'data' pois não está sendo utilizada
        // std::time_t data = std::stoll(dataStr);
        historico.adicionarRegistro(acao, detalhes);
    }
    file.close();
}

void CSVManager::salvarHistorico(const std::string& filename, const Historico& historico) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Não foi possível abrir o arquivo.");
    }

    for (const auto& registro : historico.getRegistros()) {
        file << registro.timestamp << ','
             << registro.acao << ','
             << registro.detalhes << '\n';
    }
    file.close();
}
