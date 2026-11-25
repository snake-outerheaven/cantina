#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>

class Produto {

  using string = std::string;

private:
  int codigo;
  string nome;
  double preco;
  int quantidade;

public:
  Produto(int codigo, const string &nome, double preco)
      : codigo(codigo), nome(nome), preco(preco), quantidade(0) {
    if (preco <= 0.0)
      this->preco = 1.0;
  }
  int getCodigo(void) const;
  string getNome(void) const;
  double getPreco(void) const;
  int getQuantidade(void) const;
  bool setPreco(double);
  bool adicionarEstoque(int);
  bool removerEstoque(int);
  void exibir(void) const;
};

#endif
