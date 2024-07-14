# Sistema de Controle de Estoque

Este projeto implementa um sistema de controle de estoque em C++. O sistema permite gerenciar produtos perecíveis e não perecíveis, gerar relatórios, autenticar usuários e registrar histórico de movimentações. Os dados são persistidos em arquivos CSV.

## Estrutura do Projeto

O projeto é composto pelos seguintes arquivos:

### Fonte
- `main.cpp`
- `Produto.hpp` e `Produto.cpp`
- `Perecivel.hpp` e `Perecivel.cpp`
- `NaoPerecivel.hpp` e `NaoPerecivel.cpp`
- `Estoque.hpp` e `Estoque.cpp`
- `CSVManager.hpp` e `CSVManager.cpp`
- `Relatorio.hpp` e `Relatorio.cpp`
- `Usuario.hpp` e `Usuario.cpp`
- `Historico.hpp` e `Historico.cpp`

### Arquivos de Dados
- `produtos.csv`
- `movimentacoes.csv`
- `usuarios.csv`
- `historico.csv`

## Funcionalidades

- **Adicionar Produto**: Adiciona um novo produto ao estoque.
- **Remover Produto**: Remove um produto do estoque.
- **Listar Produtos**: Lista todos os produtos no estoque.
- **Buscar Produto**: Busca um produto pelo nome.
- **Gerar Relatórios**: Gera relatórios sobre o estoque.
- **Carregar Estoque de Arquivo CSV**: Carrega os dados do estoque a partir de um arquivo CSV.
- **Salvar Estoque em Arquivo CSV**: Salva os dados do estoque em um arquivo CSV.
- **Exibir Histórico**: Exibe o histórico de movimentações do estoque.

## Compilação e Execução

### Compilação

Para compilar o projeto, você pode usar o seguinte `Makefile`:

```makefile
# Compilador e flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall

# Diretórios
SRC_DIR = .
OBJ_DIR = obj
BIN_DIR = bin

# Arquivos
TARGET = $(BIN_DIR)/controle_estoque
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))

# Regras
all: $(TARGET)

$(TARGET): $(OBJECTS)
	@if not exist $(BIN_DIR) mkdir $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@if exist $(OBJ_DIR) rmdir /S /Q $(OBJ_DIR)
	@if exist $(BIN_DIR) rmdir /S /Q $(BIN_DIR)

run: all
	$(TARGET)

.PHONY: all clean run

Execução
Após a compilação, você pode executar o programa com o seguinte comando:

sh
Copiar código
make run
Estrutura das Classes
Classe Produto
Arquivo: Produto.hpp, Produto.cpp

Classe base que representa um produto no estoque.

Atributos
std::string nome
std::string sku
std::string descricao
double precoCusto
double precoVenda
int quantidade
int lote
Date dataRecebimento
Date dataFabricacao
Date dataValidade
std::string categoria
std::string localizacao
std::string fornecedor
std::string unidadeMedida
double pesoVolume
std::string notas
std::string imagem
Métodos
Construtores, getters e setters.
virtual void mostrarDetalhes() const = 0;
Classe Perecivel
Arquivo: Perecivel.hpp, Perecivel.cpp

Classe derivada de Produto que representa um produto perecível.

Métodos
Construtor.
Implementação do método mostrarDetalhes.
Classe NaoPerecivel
Arquivo: NaoPerecivel.hpp, NaoPerecivel.cpp

Classe derivada de Produto que representa um produto não perecível.

Métodos
Construtor.
Implementação do método mostrarDetalhes.
Classe Estoque
Arquivo: Estoque.hpp, Estoque.cpp

Classe que gerencia o estoque de produtos.

Atributos
std::vector<std::unique_ptr<Produto>> produtos
int limiteMinimo
Métodos
Construtor.
Métodos para adicionar, remover, buscar e listar produtos.
Métodos para gerar relatórios.
Classe CSVManager
Arquivo: CSVManager.hpp, CSVManager.cpp

Classe que gerencia a leitura e escrita de dados em arquivos CSV.

Métodos
static void carregarProdutos(const std::string& filename, Estoque& estoque);
static void salvarProdutos(const std::string& filename, const Estoque& estoque);
static void carregarMovimentacoes(const std::string& filename, Historico& historico);
static void salvarMovimentacoes(const std::string& filename, const Historico& historico);
static void carregarUsuarios(const std::string& filename, std::vector<Usuario>& usuarios);
static void salvarUsuarios(const std::string& filename, const std::vector<Usuario>& usuarios);
static void carregarHistorico(const std::string& filename, Historico& historico);
static void salvarHistorico(const std::string& filename, Historico& historico);
Classes Relatorio
Arquivo: Relatorio.hpp, Relatorio.cpp

Classes que geram diferentes tipos de relatórios do estoque.

Classes
RelatorioBaixaQuantidade
RelatorioVencidos
RelatorioLucroEsperado
RelatorioPorCategoria
RelatorioInventarioTotal
RelatorioVencimentoProximo
Classe Usuario
Arquivo: Usuario.hpp, Usuario.cpp

Classe que representa um usuário do sistema.

Atributos
std::string nome
std::string senha
bool administrador
Métodos
Construtor, getters e setters.
bool autenticar(const std::string& senha) const;
Classe Historico
Arquivo: Historico.hpp, Historico.cpp

Classe que gerencia o histórico de movimentações do estoque.

Atributos
std::vector<Registro> registros
Métodos
Métodos para adicionar e exibir registros.
Exemplo de Uso
main.cpp
cpp
Copiar código
#include <iostream>
#include <memory>
#include <vector>
#include <locale>
#include "Produto.hpp"
#include "Perecivel.hpp"
#include "NaoPerecivel.hpp"
#include "Estoque.hpp"
#include "CSVManager.hpp"
#include "Relatorio.hpp"
#include "Usuario.hpp"
#include "Historico.hpp"

void mostrarMenu() {
    std::cout << "===== Sistema de Controle de Estoque =====" << std::endl;
    std::cout << "1. Adicionar Produto" << std::endl;
    std::cout << "2. Remover Produto" << std::endl;
    std::cout << "3. Listar Produtos" << std::endl;
    std::cout << "4. Buscar Produto" << std::endl;
    std::cout << "5. Gerar Relatórios" << std::endl;
    std::cout << "6. Carregar Estoque de Arquivo CSV" << std::endl;
    std::cout << "7. Salvar Estoque em Arquivo CSV" << std::endl;
    std::cout << "8. Exibir Histórico" << std::endl;
    std::cout << "9. Sair" << std::endl;
    std::cout << "Escolha uma opção: ";
}

void mostrarMenuRelatorios() {
    std::cout << "===== Relatórios =====" << std::endl;
    std::cout << "1. Relatório de Baixa Quantidade" << std::endl;
    std::cout << "2. Relatório de Produtos Vencidos" << std::endl;
    std::cout << "3. Relatório de Lucro Esperado" << std::endl;
    std::cout << "4. Relatório por Categoria" << std::endl;
    std::cout << "5. Relatório de Inventário Total" << std::endl;
    std::cout << "6. Relatório de Vencimento Próximo" << std::endl;
    std::cout << "7. Voltar ao Menu Principal" << std::endl;
    std::cout << "Escolha uma opção: ";
}

int main() {
    try {
        std::locale::global(std::locale("pt_BR.UTF-8"));
    } catch (const std::runtime_error& e) {
        std::cerr << "Erro ao configurar locale: " << e.what() << std::endl;
        return 1;
    }

    Estoque estoque(5);
    Historico historico;
    std::vector<Usuario> usuarios = {
        Usuario("admin", "admin123", true),
        Usuario("user", "user123", false)
    };

    std::string nomeUsuario, senha;
    std::cout << "Usuário: ";
    std::cin >> nomeUsuario;
    std::cout << "Senha: ";
    std::cin >> senha;

    Usuario* usuarioLogado = nullptr;
    for (auto& usuario : usuarios) {
        if (usuario.getNome() == nomeUsuario && usuario.autenticar(senha)) {
            usuarioLogado = &usuario;
            break;
        }
    }

    if (!usuarioLogado) {
        std::cout << "Usuário ou senha inválidos!" << std::endl;
        return 1;
    }

    std::cout << "Bem-vindo, " << usuarioLogado->getNome() << "!" << std::endl;

    int opcao;
    do {
        mostrarMenu();
        std::cin >> opcao;
        std::cin.ignore();  // Ignorar nova linha após a escolha da opção

        switch (opcao) {
        case 1: {
            if (!usuarioLogado->isAdmin()) {
                std::cout << "Permissão negada. Somente administradores podem adicionar produtos." << std::endl;
                break;
            }

            std::string tipo, nome, sku, descricao, categoria, localizacao, fornecedor, unidadeMedida, notas, imagem, dataRecebimentoStr, dataFabricacaoStr, dataValidadeStr;
            double precoCusto, precoVenda;
            int quantidade, lote;
            double pesoVolume;

            std::cout << "Tipo de produto (Perecivel/NaoPerecivel): ";
            std::getline(std::cin, tipo);
            std::cout << "Nome: ";
            std::getline(std::cin, nome);
            std::cout << "SKU: ";
            std::getline(std::cin, sku);
            std::cout << "Descrição: ";
            std::getline(std::cin, descricao);
            std::cout << "Preço de Custo: ";
            std::cin >> precoCusto;
            std::cout << "Preço de Venda: ";
            std::cin >> precoVenda;
            std::cout << "Quantidade: ";
            std::cin >> quantidade;
            std::cout << "Lote: ";
            std::cin >> lote;
            std::cin.ignore();  // Ignorar nova linha após a entrada de um número
            std::cout << "Data de Recebimento (DD/MM/YYYY): ";
            std::getline(std::cin, dataRecebimentoStr);
            std::cout << "Data de Fabricação (DD/MM/YYYY): ";
            std::getline(std::cin, dataFabricacaoStr);
            std::cout << "Data de Validade (DD/MM/YYYY): ";
            std::getline(std::cin, dataValidadeStr);
            std::cout << "Categoria: ";
            std::getline(std::cin, categoria);
            std::cout << "Localização: ";
            std::getline(std::cin, localizacao);
            std::cout << "Fornecedor: ";
            std::getline(std::cin, fornecedor);
            std::cout << "Unidade de Medida: ";
            std::getline(std::cin, unidadeMedida);
            std::cout << "Peso/Volume: ";
            std::cin >> pesoVolume;
            std::cin.ignore();  // Ignorar nova linha após a entrada de um número
            std::cout << "Notas: ";
            std::getline(std::cin, notas);
            std::cout << "Imagem: ";
            std::getline(std::cin, imagem);

            Date dataRecebimento(dataRecebimentoStr);
            Date dataFabricacao(dataFabricacaoStr);
            Date dataValidade(dataValidadeStr);

            if (tipo == "Perecivel") {
                auto produto = std::make_unique<Perecivel>(nome, sku, descricao, precoCusto, precoVenda, quantidade, lote, dataRecebimento, dataFabricacao, dataValidade, categoria, localizacao, fornecedor, unidadeMedida, pesoVolume, notas, imagem);
                estoque.adicionarProduto(std::move(produto));
                historico.adicionarRegistro("Adicionar Produto", "Adicionado produto perecível: " + nome);
            } else if (tipo == "NaoPerecivel") {
                auto produto = std::make_unique<NaoPerecivel>(nome, sku, descricao, precoCusto, precoVenda, quantidade, lote, dataRecebimento, dataFabricacao, dataValidade, categoria, localizacao, fornecedor, unidadeMedida, pesoVolume, notas, imagem);
                estoque.adicionarProduto(std::move(produto));
                historico.adicionarRegistro("Adicionar Produto", "Adicionado produto não perecível: " + nome);
            } else {
                std::cout << "Tipo de produto inválido." << std::endl;
            }

            break;
        }
        case 2: {
            if (!usuarioLogado->isAdmin()) {
                std::cout << "Permissão negada. Somente administradores podem remover produtos." << std::endl;
                break;
            }

            std::string nome;
            std::cout << "Nome do produto a remover: ";
            std::getline(std::cin, nome);
            try {
                estoque.removerProduto(nome);
                historico.adicionarRegistro("Remover Produto", "Removido produto: " + nome);
                std::cout << "Produto removido com sucesso." << std::endl;
            } catch (const std::exception& e) {
                std::cout << "Erro: " << e.what() << std::endl;
            }
            break;
        }
        case 3: {
            std::cout << "Produtos no estoque:" << std::endl;
            estoque.listarProdutos();
            break;
        }
        case 4: {
            std::string nome;
            std::cout << "Nome do produto a buscar: ";
            std::getline(std::cin, nome);
            Produto* produto = estoque.buscarProduto(nome);
            if (produto) {
                produto->mostrarDetalhes();
            } else {
                std::cout << "Produto não encontrado." << std::endl;
            }
            break;
        }
        case 5: {
            int opcaoRelatorio;
            do {
                mostrarMenuRelatorios();
                std::cin >> opcaoRelatorio;
                std::cin.ignore();  // Ignorar nova linha após a escolha da opção

                switch (opcaoRelatorio) {
                case 1: {
                    RelatorioBaixaQuantidade relatorio;
                    relatorio.gerar(estoque);
                    break;
                }
                case 2: {
                    RelatorioVencidos relatorio;
                    relatorio.gerar(estoque);
                    break;
                }
                case 3: {
                    RelatorioLucroEsperado relatorio;
                    relatorio.gerar(estoque);
                    break;
                }
                case 4: {
                    RelatorioPorCategoria relatorio;
                    relatorio.gerar(estoque);
                    break;
                }
                case 5: {
                    RelatorioInventarioTotal relatorio;
                    relatorio.gerar(estoque);
                    break;
                }
                case 6: {
                    int dias;
                    std::cout << "Digite o número de dias para o vencimento próximo: ";
                    std::cin >> dias;
                    RelatorioVencimentoProximo relatorio(dias);
                    relatorio.gerar(estoque);
                    break;
                }
                case 7:
                    std::cout << "Voltando ao menu principal..." << std::endl;
                    break;
                default:
                    std::cout << "Opção inválida. Tente novamente." << std::endl;
                    break;
                }
            } while (opcaoRelatorio != 7);
            break;
        }
        case 6: {
            std::string filename;
            std::cout << "Nome do arquivo CSV para carregar: ";
            std::getline(std::cin, filename);
            try {
                CSVManager::carregarProdutos(filename, estoque);
                historico.adicionarRegistro("Carregar Estoque", "Estoque carregado do arquivo: " + filename);
                std::cout << "Estoque carregado com sucesso." << std::endl;
            } catch (const std::exception& e) {
                std::cout << "Erro: " << e.what() << std::endl;
            }
            break;
        }
        case 7: {
            std::string filename;
            std::cout << "Nome do arquivo CSV para salvar: ";
            std::getline(std::cin, filename);
            try {
                CSVManager::salvarProdutos(filename, estoque);
                historico.adicionarRegistro("Salvar Estoque", "Estoque salvo no arquivo: " + filename);
                std::cout << "Estoque salvo com sucesso." << std::endl;
            } catch (const std::exception& e) {
                std::cout << "Erro: " << e.what() << std::endl;
            }
            break;
        }
        case 8: {
            std::cout << "Histórico de Movimentações:" << std::endl;
            historico.exibirHistorico();
            break;
        }
        case 9:
            std::cout << "Saindo..." << std::endl;
            break;
        default:
            std::cout << "Opção inválida. Tente novamente." << std::endl;
            break;
        }

    } while (opcao != 9);

    return 0;
}
