#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cerrno>
#include <cstring>
#include "Produto.hpp"
#include "BancoDados.hpp"

BancoDados::BancoDados(vector<Produto> dados){
    this->_dados = dados;
}

bool BancoDados::adicionaBanco(){
    fstream arquivo;
    arquivo.open("BancoDados.csv", ios::out | ios::app);
    if(!arquivo.is_open()){
        cerr << "Não foi possivel abrir o arquivo: BancoDados.csv" << endl;
        return false;
    } 
    else{
        for(vector<Produto>::iterator it = this->_dados.begin(); it != this->_dados.end(); ++it){
            arquivo << it->acessoID() << "," << it->acessoNOME() << "," << it->acessoMARCA() << "," << it->acessoPRECO() << "," << it->acessoSETOR() << "," << it->acessoFORNECEDOR() << endl;
        }
        arquivo.close();
        return true;
    }   
}

bool BancoDados::removeBanco(int id_remover){
    string linha;
    const string Original = "BancoDados.csv";
    bool encontrou = false;
    int id;
    
    ifstream arquivo(Original);
    ofstream temp_arq("Auxiliar.csv");
    
    if(!arquivo.is_open() || !temp_arq.is_open()){
        cerr << "Nao foi possivel abrir o arquivo" << endl;
        return false;
    } 
    else{
        while(getline(arquivo, linha)){
            size_t pos = linha.find(',');
            string id_ver = linha.substr(0, pos);
            id = stoi(id_ver);

            if(id_remover != id)
                temp_arq << linha << endl;
            else    
                encontrou = true;
        }
        arquivo.close();
        temp_arq.close();

        if(encontrou){
            if(rename("Auxiliar.csv", Original.c_str()) != 0)
                cerr << "Erro ao renomear o arquivo!" << std::strerror(errno) << endl;
            else    
                cout << "Arquivo renomeado com sucesso!" << std::endl;     
        } 
        else{
            remove("Auxiliar.csv");
            cout << "Esse produto não esta no estoque!" << endl;
            return false;
        }
    return true;
}
}

