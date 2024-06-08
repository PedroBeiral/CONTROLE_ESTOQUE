# Sistema de Controle de Estoque para Mercado

Este repositório contém o código-fonte do projeto "Sistema de Controle de Estoque para Mercado", desenvolvido como parte do curso de Programação e Desenvolvimento de Software 2 na UFMG.

## Descrição

O Sistema de Controle de Estoque para Mercado é uma aplicação que permite gerenciar o estoque de um mercado, oferecendo funcionalidades para adicionar, remover e atualizar produtos, além de gerar relatórios detalhados e notificações automáticas para produtos em baixa quantidade. O sistema utiliza um arquivo CSV como banco de dados para armazenar as informações dos produtos.

## Funcionalidades

- **Adicionar Produtos ao Estoque:** Permite registrar novos produtos com nome, categoria, quantidade e preço.
- **Atualizar Quantidade de Produtos:** Permite aumentar ou diminuir a quantidade de produtos no estoque.
- **Remover Produtos do Estoque:** Permite remover produtos do estoque.
- **Gerar Relatórios de Estoque:** Gera relatórios detalhados com informações de todos os produtos.
- **Notificações de Produtos em Baixa:** Notifica automaticamente quando a quantidade de um produto está abaixo de um limite especificado.

## Tecnologias Utilizadas

- Linguagem de Programação: C++11
- Biblioteca para Testes: Google Test (opcional)
- Sistema de Controle de Versão: Git
- Plataforma de Hospedagem de Código: GitHub

## Como Usar

1. Clone este repositório:
    ```bash
    git clone https://github.com/seu-usuario/sistema-controle-estoque.git
    ```

2. Navegue até o diretório do projeto:
    ```bash
    cd sistema-controle-estoque
    ```

3. Compile o projeto usando `make`:
    ```bash
    make
    ```

4. Execute o programa:
    ```bash
    ./controle_estoque
    ```


