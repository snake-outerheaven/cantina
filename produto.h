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
  Produto(int codigo, const string &nome, double preco);
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
