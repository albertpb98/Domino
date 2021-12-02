#ifndef PILA_H
#define PILA_H

#include "ficha.h"
#include "colores.h"

typedef struct {
	int	n_fichas;
	tficha	f[NUM_FICHAS_DOMINO];
} tpila;

void inicializar_pila(tpila *p);
void imprimir_pila(tpila p, int visible);
tficha coger_ficha(tpila *p);
int pila_vacia(tpila p);

#endif // PILA_H

