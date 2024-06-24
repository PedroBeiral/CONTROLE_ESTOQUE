#include "Data.hpp"
#include <sstream>
#include <ctime>

Data::Data(int dia, int mes, int ano) : dia(dia), mes(mes), ano(ano) {}

std::string Data::toString() const {
    std::ostringstream oss;
    oss << (dia < 10 ? "0" : "") << dia << "/"
        << (mes < 10 ? "0" : "") << mes << "/"
        << ano;
    return oss.str();
}

int Data::diasEntre(const Data& outra) const {
    std::tm a = {0, 0, 0, dia, mes - 1, ano - 1900}; // std::tm month is 0-11, year since 1900
    std::tm b = {0, 0, 0, outra.dia, outra.mes - 1, outra.ano - 1900};
    std::time_t x = std::mktime(&a);
    std::time_t y = std::mktime(&b);
    return std::difftime(y, x) / (60 * 60 * 24);
}

bool Data::estaProximoDoVencimento() const {
    std::time_t agora = std::time(nullptr);
    std::tm* dataAtual = std::localtime(&agora);
    Data hoje(dataAtual->tm_mday, dataAtual->tm_mon + 1, dataAtual->tm_year + 1900);

    return diasEntre(hoje) <= 30; // Considera 30 dias como "próximo do vencimento"
}
