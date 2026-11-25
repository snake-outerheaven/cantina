#ifndef CANTINA_H
#define CANTINA_H

#include "produto.h"
#include <vector>
#include <string>


class Cantina {

	using vector = std::vector;
	using string = std::string;

	private:

		vector<Produto> produtos;
		double caixa;


		int buscarIndice(int codigo) const;


	public:
		
		Cantina(void); // construtor, caixa inicializa em zero
		bool cadastrarProduto(int codigo, string& nome, double preco);
		bool repor(int codigo, int quantidade);
		bool vender(int codigo, int quantidade);
		bool alterarPreco(int codigo, double preco);
		void listarProdutos(void) const;
		double getCaixa(void) const;
};
#endif
