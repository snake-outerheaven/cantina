#pragma once

/*
 * API de produtos da cantina, desculpa professor, mas nao to com saco de
 * classes, vou fazer encapsulamento em C sim
 */

typedef struct item_t item_t;
item_t *createItem(int id, const char *nome, double preco, int quant);
void destroyItem(item_t **it);

int getId(const item_t *it);
const char *getNome(const item_t *it);
double getPreco(const item_t *it);
int getQuant(const item_t *it);

int setPreco(item_t *it, double preco); /* 1 ok, 0 erro */
int addEstoque(item_t *it, int quant);
int remEstoque(item_t *it, int quant);

void exibir(const item_t *it);
