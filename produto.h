#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>


class Produto {


	using string = std::string; // esconde no contexto da classe, pois tudo dentro de um class por si so e privado, o private abaixo e apenas para se adequar
				    // ao trabalho hehehe

	private:
		int cod;
		string nome;
		double pric;
		int quant;

	public:

		Produto(int cod, const string& nome, double prec) : cod(cod), nome(nome), pric(price), quant(0) {}

		int getCod(void) const;
		string getNm(void) const;
		double getPric(void) const;
		int getQuant(void) const;
		bool setPreco(double);
		bool addStock(double);
		bool remStock(double);
		void exibir(void) const;

};

#endif 
