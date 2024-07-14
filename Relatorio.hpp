#ifndef RELATORIO_HPP
#define RELATORIO_HPP

#include "Estoque.hpp"

class Relatorio {
public:
    virtual ~Relatorio() = default;
    virtual void gerar(const Estoque& estoque) const = 0;
};

class RelatorioBaixaQuantidade : public Relatorio {
public:
    void gerar(const Estoque& estoque) const override;
};

class RelatorioVencidos : public Relatorio {
public:
    void gerar(const Estoque& estoque) const override;
};

class RelatorioLucroEsperado : public Relatorio {
public:
    void gerar(const Estoque& estoque) const override;
};

class RelatorioPorCategoria : public Relatorio {
public:
    void gerar(const Estoque& estoque) const override;
};

class RelatorioInventarioTotal : public Relatorio {
public:
    void gerar(const Estoque& estoque) const override;
};

class RelatorioVencimentoProximo : public Relatorio {
private:
    int dias;
public:
    RelatorioVencimentoProximo(int dias);
    void gerar(const Estoque& estoque) const override;
};

#endif // RELATORIO_HPP
