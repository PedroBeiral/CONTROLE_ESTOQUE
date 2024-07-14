#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>

class Usuario {
private:
    std::string nome;
    std::string senha;
    bool administrador;

public:
    Usuario(const std::string& nome, const std::string& senha, bool administrador);
    std::string getNome() const;
    std::string getSenha() const;
    bool autenticar(const std::string& senha) const;
    bool isAdmin() const;
};

#endif // USUARIO_HPP
