#ifndef CANTINA_H
#define CANTINA_H

#include "produto.h"
#include <string>
#include <vector>

class Cantina {

  using string = std::string;

private:
  std::vector<Produto> produtos;
  double caixa;

#include "produto.h"
#include <string>
#include <vector>

  class Cantina {

    using string = std::string;

  private:
    std::vector<Produto> produtos;
    double caixa;

    int buscarIndice(int codigo) const;

  public:
    Cantina(void); // construtor, caixa inicializa em zero
    bool cadastrarProduto(int codigo, const string &nome, double preco);
    bool repor(int codigo, int quantidade);
    bool vender(int codigo, int quantidade);
    bool alterarPreco(int codigo, double preco);
    void listarProdutos(void) const;
    double getCaixa(void) const;
  };
#endif
