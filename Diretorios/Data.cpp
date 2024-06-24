#include "Data.hpp"
#include <sstream>
#include <iomanip>
#include <ctime>

// Construtor que inicializa uma data com dia, mês e ano
Data::Data(int dia, int mes, int ano) : dia(dia), mes(mes), ano(ano) {}

// Calcula a diferença em dias entre duas datas
int Data::diferencaDias(const Data& outra) const {
    std::tm a = {0, 0, 0, dia, mes - 1, ano - 1900};
    std::tm b = {0, 0, 0, outra.dia, outra.mes - 1, outra.ano - 1900};
    std::time_t x = std::mktime(&a);
    std::time_t y = std::mktime(&b);
    return std::difftime(y, x) / (60 * 60 * 24);
}

// Verifica se a data está próxima do vencimento (menos de 30 dias)
bool Data::estaProximoDoVencimento() const {
    Data hoje(26, 6, 2024); // Data atual para comparação
    return diferencaDias(hoje) < 30;
}

// Retorna a data em formato string
std::string Data::toString() const {
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << dia << "/"
        << std::setw(2) << std::setfill('0') << mes << "/"
        << ano;
    return oss.str();
}
