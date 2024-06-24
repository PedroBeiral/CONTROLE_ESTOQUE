#ifndef DATA_HPP
#define DATA_HPP

#include <string>

// Classe Data representa uma data com dia, mês e ano
class Data {
public:
    // Construtor que inicializa uma data com dia, mês e ano
    Data(int dia, int mes, int ano);

    // Calcula a diferença em dias entre duas datas
    int diferencaDias(const Data& outra) const;

    // Verifica se a data está próxima do vencimento (menos de 30 dias)
    bool estaProximoDoVencimento() const;

    // Retorna a data em formato string
    std::string toString() const;

private:
    int dia;  // Dia da data
    int mes;  // Mês da data
    int ano;  // Ano da data
};

#endif // DATA_HPP
