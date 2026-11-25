#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>

class Produto {

  using string =
      std::string; // esconde no contexto da classe, pois tudo dentro de um
                   // class por si so e privado, o private abaixo e apenas para
                   // se adequar ao trabalho hehehe

private:
  int codigo;
  string nome;
  double preco;
  int quantidade;

public:
  Produto(int codigo, const string &nome, double preco)
      : codigo(codigo), nome(nome), preco(preco), quantidade(0) {}
  int getQuant(void) const;
  string getNome(void) const;
  double getPreco(void) const;
  int getQuantidade(void) const;
  bool setPreco(double);
  bool adicionarEstoque(int);
  bool removerEstoque(int);
  void exibir(void) const;
};

#endif
