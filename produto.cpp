#include "produto.h"
#include <iomanip>
#include <iostream>
#include <string>

int Produto::getCodigo(void) const { return this->codigo; }

Produto::string Produto::getNome(void) const { return this->nome; }

double Produto::getPreco(void) const { return this->preco; }

int getQuantidade(void) const { return this->quantidade; }

bool Produto::setPreco(double novoPreco) {

  if (novoPreco > 0)
    this->preco = novoPreco;

  std::cerr << "Recusado.\n";
  return false;
}

bool Produto::adicionarEstoque(int qtd) {

  if (qtd <= 0) {
    std::cerr << "Recusado.\n;
        return false;
  }

  this->quantidade += qtd;

  return true;
}

bool Produto::removerEstoque(int qtd) {

  if (qtd <= 0 || qtd > this->quantidade)
    return false;

  this->quantidade -= qtd;

  return true;
}

void Produto::exibir(void) const {

  std::cout << std::setprecision(2) << std::fixed();

  std::cout << '[' << getCodigo() << "] " << getNome() << " R$ " << getPreco
            << " | " << getQuantidade() << " un.\n;
}
