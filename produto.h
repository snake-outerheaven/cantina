#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct item_t item_t;
item_t *createItem(int id, const char *nome, double preco, int quant);
void destroyItem(item_t **it);

int getId(const item_t *it, int *dst);
int getNome(const item_t *it, char *dst);
int getPreco(const item_t *it, double *dst);
int getQuant(const item_t *it);

int setPreco(item_t *it, double preco); /* 1 ok, 0 erro */
int addEstoque(item_t *it, int quant);
int remEstoque(item_t *it, int quant);

void exibir(const item_t *it);

#endif
