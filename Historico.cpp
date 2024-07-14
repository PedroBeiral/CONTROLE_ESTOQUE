#include "Historico.hpp"
#include <iostream>
#include <iomanip>

void Historico::adicionarRegistro(const std::string& acao, const std::string& detalhes) {
    std::time_t agora = std::time(nullptr);
    registros.push_back({agora, acao, detalhes});
}

void Historico::exibirHistorico() const {
    for (const auto& registro : registros) {
        std::cout << std::put_time(std::localtime(&registro.timestamp), "%Y-%m-%d %H:%M:%S")
                  << " - " << registro.acao << ": " << registro.detalhes << std::endl;
    }
}

const std::vector<Historico::Registro>& Historico::getRegistros() const {
    return registros;
}
