#include "cantina.h"
#include "produto.h"
#include <iostream>

int Cantina::buscarIndice(int codigo) const {

  for (size_t i{0}; i < produtos.size(); i++)
    if (codigo == produtos.at(i).getCodigo())
      return i;
  // complexidade O(N), com sort, da pra fazer busca binaria e reduzir

  return -1;
}

Cantina::Cantina(void) : caixa(0.0) {}

bool Cantina::cadastrarProduto(int codigo, const Cantina::string &nome,
                               double preco) {

  if (codigo <= 0 || nome.empty() || preco <= 0)
    return false;

  if (buscarIndice(codigo) == -1) {
    Produto p(codigo, nome, preco);
    produtos.push_back(p);
    return true;
  }

  return false;
}

bool Cantina::repor(int codigo, int quantidade) {

  int i;
  if ((i = buscarIndice(codigo)) == -1)
    return false;

  if (produtos.at(i).adicionarEstoque(quantidade))
    return true;

  return false;
}

bool Cantina::vender(int codigo, int quantidade) {

  int i;
  if ((i = buscarIndice(codigo)) == -1)
    return false;

  if (produtos.at(i).removerEstoque(quantidade)) {
    caixa += produtos.at(i).getPreco() * static_cast<double>(quantidade);
    return true;
  }

  return false;
}

bool Cantina::alterarPreco(int codigo, double preco) {

  int i;
  if ((i = buscarIndice(codigo)) == -1)
    return false;

  if (produtos.at(i).setPreco(preco))
    return true;

  return false;
}

void Cantina::listarProdutos(void) const {

  if (this->produtos.empty())
    std::cerr << "Estoque vazio.\n";

  for (size_t i = 0; i < produtos.size(); i++)
    produtos.at(i).exibir();
}

double Cantina::getCaixa(void) const { return this->caixa; }
