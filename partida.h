#ifndef PARTIDA_H
#define PARTIDA_H

#include "jugador.h"
#include "mesa.h"
#include "pila.h"
#include "tirada.h"

typedef struct {
	tjugadores	js;
	tmesa		m;
	tpila		p;
	int		visible;
	int		mesa_2d;
	int		pasadas;
} tpartida;


void inicializar_partida(tpartida *pa);
void imprimir_estado_partida(tpartida pa);
void realizar_jugada(tpartida *pa);
int se_ha_acabado_la_partida(tpartida pa);
void finalizar_partida(tpartida pa);
#endif // PARTIDA_H
