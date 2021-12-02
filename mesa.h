#ifndef MESA_H
#define MESA_H

#include "ficha.h"
#include "colores.h"

#define NUMF 28
#define FMAX 28
#define NUM_FICHAS_DOMINO 28

typedef struct
{
	int n_fichas;
	tficha mesa[FMAX];
}tmesa;


void inicializar_mesa(tmesa *m);
void imprimir_mesa(tmesa m);

void pon_en_mesa_por_la_derecha(tmesa *m, tficha f);
void pon_en_mesa_por_la_izquierda(tmesa *m, tficha f);

int extremo_izquierdo_mesa(tmesa m);
int extremo_derecho_mesa(tmesa m);

#endif // MESA_H

