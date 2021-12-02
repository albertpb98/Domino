#ifndef TIRADA_H
#define TIRADA_H

#include "jugador.h"
#include "mesa.h"
#include "colores.h"

#define MAX_TIRADAS_JUGADOR	NUM_FICHAS_DOMINO

typedef struct {
	int n_ficha;	// numero de ficha en el vector de fichas del jugador
	char extremo;	// IZQUIERDA o DERECHA (de n_ficha(1))
	int girada;	// TRUE o FALSE
} ttirada;

typedef struct {
	int		n_tiradas;
	ttirada	t[MAX_TIRADAS_JUGADOR];
} ttiradas;

void imprimir_tirada(ttirada t, tjugador j);
void imprimir_tiradas(ttiradas posibles, tjugador j);
ttiradas calcular_tiradas_posibles(tjugador j, tmesa m);

#endif // TIRADA_H

