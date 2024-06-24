#ifndef DATA_HPP
#define DATA_HPP

#include <string>

class Data {
public:
    Data(int dia, int mes, int ano);
    std::string toString() const;
    int diasEntre(const Data& outra) const;
    bool estaProximoDoVencimento() const;

private:
    int dia;
    int mes;
    int ano;
};

#endif // DATA_HPP
