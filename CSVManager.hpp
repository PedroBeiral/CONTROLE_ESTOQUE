#ifndef CSVMANAGER_HPP
#define CSVMANAGER_HPP

#include "Produto.hpp"
#include "Estoque.hpp"
#include "Usuario.hpp"
#include "Historico.hpp"
#include <string>
#include <vector>

class CSVManager {
public:
    static void carregarProdutos(const std::string& filename, Estoque& estoque);
    static void salvarProdutos(const std::string& filename, const Estoque& estoque);
    static void carregarMovimentacoes(const std::string& filename, Historico& historico);
    static void salvarMovimentacoes(const std::string& filename, const Historico& historico);
    static void carregarUsuarios(const std::string& filename, std::vector<Usuario>& usuarios);
    static void salvarUsuarios(const std::string& filename, const std::vector<Usuario>& usuarios);
    static void carregarHistorico(const std::string& filename, Historico& historico);
    static void salvarHistorico(const std::string& filename, const Historico& historico);
};

#endif // CSVMANAGER_HPP
