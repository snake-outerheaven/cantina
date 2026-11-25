// teste_produto.cpp -- FORNECIDO PELO PROFESSOR (Aula 1)
// Compile com: g++ -std=c++17 -Wall teste_produto.cpp produto.cpp -o
// teste_produto
#include "produto.h"
#include <iostream>
#include <string>

using namespace std;

void mostrar(const string &acao, bool ok) {
  cout << acao << ": " << (ok ? "ok" : "recusado") << endl;
}

int main() {
  Produto p(101, "Coxinha", 6.50);
  p.exibir(); // [101] Coxinha | R$ 6.50 | 0 un.

  mostrar("Repor 10", p.adicionarEstoque(10)); // ok
  mostrar("Repor -3", p.adicionarEstoque(-3)); // recusado
  mostrar("Vender 4", p.removerEstoque(4));    // ok
  mostrar("Vender 50", p.removerEstoque(50));  // recusado (falta estoque)
  mostrar("Preco 7.00", p.setPreco(7.00));     // ok
  mostrar("Preco -2.00", p.setPreco(-2.00));   // recusado
  p.exibir(); // [101] Coxinha | R$ 7.00 | 6 un.

  Produto q(102, "Suco", -2.00); // preco invalido no construtor
  q.exibir();                    // [102] Suco | R$ 1.00 | 0 un.

  // TESTE DO ENCAPSULAMENTO: descomente a linha abaixo e compile de novo.
  // O compilador DEVE dar erro, porque 'quantidade' e privado.
  // p.quantidade = 1000;

  return 0;
}
