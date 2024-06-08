#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

using namespace std;

class Data{

    public:
        Data(int dia, int mes, int ano);
        string leData(Data data);
        int calcDiasEntre(const Data& dataI, const Data& dataF);
    
    private:
        int dia;
        int mes;
        int ano;    
};

#endif