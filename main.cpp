#include <iostream>
#include <vector>
#include <string>
#include "Produto.hpp"
#include "ProdutoPerecivel.hpp"
#include "BancoDados.hpp"
#include "ControleEstoque.hpp"
#include "Data.hpp"

using namespace std;

// Função para exibir o menu de opções
void exibirMenu() {
    cout << "1. Adicionar Produto" << endl;
    cout << "2. Remover Produto" << endl;
    cout << "3. Atualizar Produto" << endl;
    cout << "4. Exibir Produto" << endl;
    cout << "5. Adicionar Produto Perecível" << endl;
    cout << "6. Verificar Produtos Perecíveis Próximos do Vencimento" << endl;
    cout << "7. Sair" << endl;
    cout << "Escolha uma opcao: ";
}

int main() {
    ControleEstoque controle("BancoDados.csv"); // Inicializa o controle de estoque com o arquivo de banco de dados

    int opcao;
    int id;
    string nome;
    string marca;
    double preco;
    string fornecedor;
    char setorArmazenamento;
    int dia, mes, ano;

    // Loop para exibir o menu até que o usuário escolha sair
    do {
        exibirMenu();
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "ID: ";
                cin >> id;
                cout << "Nome: ";
                cin >> nome;
                cout << "Marca: ";
                cin >> marca;
                cout << "Preco: ";
                cin >> preco;
                cout << "Fornecedor: ";
                cin >> fornecedor;
                cout << "Setor de Armazenamento: ";
                cin >> setorArmazenamento;
                controle.adicionaProduto(Produto(id, nome, marca, preco, fornecedor, setorArmazenamento));
                break;
            case 2:
                cout << "ID: ";
                cin >> id;
                controle.removeProduto(id);
                break;
            case 3:
                cout << "ID: ";
                cin >> id;
                cout << "Atributo (nome, marca, preco, setor, fornecedor): ";
                cin >> nome;
                cout << "Novo Valor: ";
                cin >> marca; // Reutilizando variáveis
                controle.atualizaProduto(id, nome, marca);
                break;
            case 4:
                cout << "ID: ";
                cin >> id;
                controle.exibeProduto(id);
                break;
            case 5:
                cout << "ID: ";
                cin >> id;
                cout << "Nome: ";
                cin >> nome;
                cout << "Marca: ";
                cin >> marca;
                cout << "Preco: ";
                cin >> preco;
                cout << "Fornecedor: ";
                cin >> fornecedor;
                cout << "Setor de Armazenamento: ";
                cin >> setorArmazenamento;
                cout << "Data de Vencimento (dia mes ano): ";
                cin >> dia >> mes >> ano;
                controle.adicionaProduto(ProdutoPerecivel(id, nome, marca, preco, fornecedor, setorArmazenamento, Data(dia, mes, ano)));
                break;
            case 6: {
                // Aqui você pode iterar pelos produtos e verificar os produtos perecíveis próximos do vencimento
                vector<Produto> produtos = controle.buscarTodosOsProdutos(); // Assumindo que você tem um método para buscar todos os produtos
                for (const auto& produto : produtos) {
                    if (ProdutoPerecivel* perecivel = dynamic_cast<ProdutoPerecivel*>(&produto)) {
                        if (perecivel->estaProximoDoVencimento()) {
                            cout << "Produto ID: " << perecivel->acessoID() << " está próximo do vencimento." << endl;
                        }
                    }
                }
                break;
            }
            case 7:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao invalida!" << endl;
                break;
        }
    } while (opcao != 7);

    return 0;
}
