#include "Relatorio.hpp"
#include <iostream>
#include <map>

void RelatorioBaixaQuantidade::gerar(const Estoque& estoque) const {
    for (const auto& produto : estoque.getProdutos()) {
        if (produto->getQuantidade() < estoque.getLimiteMinimo()) {
            std::cout << "Produto abaixo do limite mínimo: " << produto->getNome() << std::endl;
        }
    }
}

void RelatorioVencidos::gerar(const Estoque& estoque) const {
    Date hoje = Date::today();
    for (const auto& produto : estoque.getProdutos()) {
        if (produto->getDataValidade().isBefore(hoje)) {
            std::cout << "Produto com validade expirada: " << produto->getNome() << std::endl;
        }
    }
}

void RelatorioLucroEsperado::gerar(const Estoque& estoque) const {
    double lucroTotal = 0;
    for (const auto& produto : estoque.getProdutos()) {
        lucroTotal += (produto->getPrecoVenda() - produto->getPrecoCusto()) * produto->getQuantidade();
    }
    std::cout << "Lucro esperado do estoque: R$" << lucroTotal << std::endl;
}

void RelatorioPorCategoria::gerar(const Estoque& estoque) const {
    std::map<std::string, std::vector<const Produto*>> produtosPorCategoria;
    for (const auto& produto : estoque.getProdutos()) {
        produtosPorCategoria[produto->getCategoria()].push_back(produto.get());
    }

    for (const auto& categoria : produtosPorCategoria) {
        std::cout << "Categoria: " << categoria.first << std::endl;
        for (const auto& produto : categoria.second) {
            produto->mostrarDetalhes();
        }
    }
}

void RelatorioInventarioTotal::gerar(const Estoque& estoque) const {
    double valorTotal = 0;
    for (const auto& produto : estoque.getProdutos()) {
        valorTotal += produto->getPrecoVenda() * produto->getQuantidade();
    }
    std::cout << "Valor total do inventário: R$" << valorTotal << std::endl;
}

RelatorioVencimentoProximo::RelatorioVencimentoProximo(int dias) : dias(dias) {}

void RelatorioVencimentoProximo::gerar(const Estoque& estoque) const {
    Date hoje = Date::today();
    for (const auto& produto : estoque.getProdutos()) {
        Date validade = produto->getDataValidade();
        // Lógica para verificar se a validade está próxima (dentro dos próximos 'dias' dias)
        // Esta lógica pode ser aprimorada conforme necessário
        if ((validade.getYear() == hoje.getYear() && validade.getMonth() == hoje.getMonth() && validade.getDay() <= hoje.getDay() + dias) ||
            (validade.getYear() == hoje.getYear() && validade.getMonth() == hoje.getMonth() + 1 && validade.getDay() <= dias - (31 - hoje.getDay()))) {
            std::cout << "Produto com validade próxima: " << produto->getNome() << ", Validade: " << validade.toString() << std::endl;
        }
    }
}
