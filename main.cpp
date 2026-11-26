// main.cpp -- FORNECIDO PELO PROFESSOR (Aula 2). Nao precisa ser alterado.
// Compile com: g++ -std=c++17 -Wall main.cpp produto.cpp cantina.cpp -o cantina
#include "cantina.h"
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

// Le um inteiro; repete ate o usuario digitar um numero valido.
int lerInt(const string &msg) {
  int valor;
  while (true) {
    cout << msg;
    if (cin >> valor) {
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      return valor;
    }
    if (cin.eof()) {
      return 0; // fim da entrada: trata como "Sair"
    }
    cout << "Entrada invalida. Digite um numero inteiro." << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
}

// Le um numero real (use ponto: 6.50).
double lerDouble(const string &msg) {
  double valor;
  while (true) {
    cout << msg;
    if (cin >> valor) {
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      return valor;
    }
    if (cin.eof()) {
      return 0.0;
    }
    cout << "Entrada invalida. Use ponto como separador (ex.: 6.50)." << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
}

// Le uma linha inteira (permite nomes com espaco).
string lerLinha(const string &msg) {
  string texto;
  cout << msg;
  getline(cin, texto);
  return texto;
}

void resultado(bool ok, const string &msgOk, const string &msgErro) {
  cout << (ok ? msgOk : msgErro) << endl;
}

int main() {
  Cantina cantina;

  // Carga inicial para agilizar os testes
  cantina.cadastrarProduto(1, "Coxinha", 6.50);
  cantina.cadastrarProduto(2, "Suco de laranja", 5.00);
  cantina.cadastrarProduto(3, "Pao de queijo", 3.50);
  cantina.repor(1, 20);
  cantina.repor(2, 15);
  cantina.repor(3, 30);

  int opcao;
  do {
    cout << "\n===== CANTINA ESCOLAR =====" << endl;
    cout << "1 - Cadastrar produto" << endl;
    cout << "2 - Repor estoque" << endl;
    cout << "3 - Vender" << endl;
    cout << "4 - Alterar preco" << endl;
    cout << "5 - Listar produtos" << endl;
    cout << "6 - Ver caixa" << endl;
    cout << "0 - Sair" << endl;
    opcao = lerInt("Opcao: ");

    switch (opcao) {
    case 1: {
      int codigo = lerInt("Codigo: ");
      string nome = lerLinha("Nome: ");
      double preco = lerDouble("Preco: R$ ");
      resultado(cantina.cadastrarProduto(codigo, nome, preco),
                "Produto cadastrado.",
                "ERRO: dados invalidos ou codigo ja existe.");
      break;
    }
    case 2: {
      int codigo = lerInt("Codigo: ");
      int qtd = lerInt("Quantidade: ");
      resultado(cantina.repor(codigo, qtd), "Estoque atualizado.",
                "ERRO: produto inexistente ou quantidade invalida.");
      break;
    }
    case 3: {
      int codigo = lerInt("Codigo: ");
      int qtd = lerInt("Quantidade: ");
      resultado(cantina.vender(codigo, qtd), "Venda realizada.",
                "ERRO: produto inexistente ou estoque insuficiente.");
      break;
    }
    case 4: {
      int codigo = lerInt("Codigo: ");
      double preco = lerDouble("Novo preco: R$ ");
      resultado(cantina.alterarPreco(codigo, preco), "Preco alterado.",
                "ERRO: produto inexistente ou preco invalido.");
      break;
    }
    case 5:

      cantina.listarProdutos();
      break;
    case 6:
      cout << "Caixa: R$ " << fixed << setprecision(2) 1 << cantina.getCaixa()
           << endl;
      break;
    case 0:
      cout << "Ate logo!" << endl;
      break;
    default:
      cout << "Opcao invalida." << endl;
      break;
    }
  } while (opcao != 0);

  return 0;
}
