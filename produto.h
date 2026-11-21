#ifndef PRODUTO_H
#define PRODUTO_H

/*
 * Usuario so cria ponteiros de item_t e a api que lida seguramente com os
 * modelos, por nao ter definicao de tipo, usuario so pode ter um ponteiro
 * para structs do produto, sendo um padrao de desenvolvimento chamado
 * opaque pointer para manter a ABI estavel
 */

#define MAX_PROD_NAME 256

typedef struct item_t item_t;

item_t *createItem(const int, const char *, double, int); // instancia structs na heap

void destroyItem(item_t **); // ponteiro do ponteiro do chamador para tornar o ponteiro do chamador NULL

int getId(item_t const *); ; // retorna o id do produto

char *getNome(item_t const *); // retorna o ponteiro para a primeira letra do nome do produto

double getPreco(item_t const *); // retorna o preco representado em double do produto

const int getQuant(item_t const *); // returna quantidade 

int setPreco(item_t *, double); // seta um preco de um produto >= 0.0

int addStok(item_t *, int); // adiciona quantidade >= 0

int remEstok(item_t *, int); // remove estoque se > 0

void exibir(const item_t *); // exibe os metadados de um item

#endif
