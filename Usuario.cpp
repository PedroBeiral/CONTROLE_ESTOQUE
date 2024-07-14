#include "Usuario.hpp"

Usuario::Usuario(const std::string& nome, const std::string& senha, bool administrador)
    : nome(nome), senha(senha), administrador(administrador) {}

std::string Usuario::getNome() const {
    return nome;
}

std::string Usuario::getSenha() const {
    return senha;
}

bool Usuario::autenticar(const std::string& senha) const {
    return this->senha == senha;
}

bool Usuario::isAdmin() const {
    return administrador;
}
