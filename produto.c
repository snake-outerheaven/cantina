#include "produto.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF 256

struct item_t {

  int id;
  char nome[MAX_BUF];
  double preco;
  int quant;
};

item_t *createItem(int id, const char *nome, double preco, int quant) {

  item_t *i = NULL;

  if ((i = (item_t *)calloc(1, sizeof(*i))) == NULL)
    return NULL;

  i->id = id;
  strcpy(i->nome, nome); /* o main cuida da seguranca de buffer */
  i->preco = preco;
  i->quant = quant;

  return i;
}

void destroyItem(item_t **it) {

  if (it == NULL || *it == NULL)
    return;

  free(*it);

  *it = NULL;
}

int getId(const item_t *it, int *dst) {

	if (it == NULL || dst == NULL)
		return EXIT_FAILURE;

	*dst = it->id;

	return EXIT_SUCCESS;
}

int getNome(const item_t *it, char *dst)
{
	if (it == NULL || dst == NULL)
		return EXIT_FAILURE;


	strcpy(dst, it->nome);

	return EXIT_SUCCESS;
}
