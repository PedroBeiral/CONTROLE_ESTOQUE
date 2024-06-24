# Sistema de Controle de Estoque para Mercado

Este repositório contém o código-fonte do projeto "Sistema de Controle de Estoque para Mercado", desenvolvido como parte do curso de Programação e Desenvolvimento de Software 2 na UFMG.

## Descrição Geral
O Sistema de Controle de Estoque para Mercado é uma aplicação que permite gerenciar o estoque de um mercado, oferecendo funcionalidades para adicionar, remover e atualizar produtos, além de gerar relatórios detalhados e notificações automáticas para produtos em baixa quantidade. O sistema utiliza um arquivo CSV como banco de dados para armazenar as informações dos produtos.

## Funcionalidades
- **Adicionar Produtos ao Estoque**: Permite registrar novos produtos com nome, categoria, quantidade e preço.
- **Atualizar Quantidade de Produtos**: Permite aumentar ou diminuir a quantidade de produtos no estoque.
- **Remover Produtos do Estoque**: Permite remover produtos do estoque.
- **Gerar Relatórios de Estoque**: Gera relatórios detalhados com informações de todos os produtos.
- **Notificações de Produtos em Baixa**: Notifica automaticamente quando a quantidade de um produto está abaixo de um limite especificado.

## Tecnologias Utilizadas
- Linguagem de Programação: C++11
- Sistema de Controle de Versão: Git
- Plataforma de Hospedagem de Código: GitHub

## Estrutura do Projeto
- `src/BancoDados.hpp` / `src/BancoDados.cpp`: Implementação das operações de banco de dados.
- `src/ControleEstoque.hpp` / `src/ControleEstoque.cpp`: Controle do estoque e operações sobre produtos.
- `src/Produto.hpp` / `src/Produto.cpp`: Representação de um produto.
- `src/ProdutoPerecivel.hpp` / `src/ProdutoPerecivel.cpp`: Representação de um produto perecível.
- `src/Data.hpp` / `src/Data.cpp`: Manipulação de datas para produtos perecíveis.
- `src/main.cpp`: Arquivo principal para interação com o usuário.
- `CRC_Cards`: Documentação dos cartões CRC.
- `Makefile`: Script para compilação do projeto.
- `BancoDados.csv`: Arquivo CSV usado como banco de dados.

## Instruções de Instalação
Para compilar e executar o projeto, siga os passos abaixo:

1. Clone o repositório:
   ```sh
   git clone https://github.com/seu-usuario/seu-repositorio.git
   cd seu-repositorio
