#ifndef JUGADOR_H
#define JUGADOR_H

#include "ficha.h"


#define MIN_JUGADORES	2
#define MAX_JUGADORES	4

#define T_HUMANO	1
#define T_ROBOT		2

typedef struct {
	int	n_fichas;
	tficha	f[NUM_FICHAS_DOMINO];	// Fichas que tiene
	int	tipo;
}tjugador;

typedef struct {
	int n_jugadores;
	int un_humano;	// TRUE or FALSE
	int turno;
	tjugador	j[MAX_JUGADORES]; // Fichas que tiene y otras cosas
}tjugadores;

void print_jugador(tjugador j, int visible);
void printar_jugadores(tjugadores js, int visible);
void que_jugador_tiene_doble_mas_alto(tjugadores js, int *p_nj, int *p_nf);
void pasar_turno(tjugadores *p_js);
void imprimir_turno(tjugadores js);

#endif // JUGADOR_H

