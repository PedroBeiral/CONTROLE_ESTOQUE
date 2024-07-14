#ifndef HISTORICO_HPP
#define HISTORICO_HPP

#include <string>
#include <vector>
#include <ctime>

class Historico {
private:
    struct Registro {
        std::time_t timestamp;
        std::string acao;
        std::string detalhes;
    };
    std::vector<Registro> registros;

public:
    void adicionarRegistro(const std::string& acao, const std::string& detalhes);
    void exibirHistorico() const;
    const std::vector<Registro>& getRegistros() const;
};

#endif // HISTORICO_HPP
