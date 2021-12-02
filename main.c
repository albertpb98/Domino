#include <stdio.h>
#include "partida.h"
#include "pila.h"
#include "jugador.h"
#include "ficha.h"
#include "tirada.h"
#include "preguntas.h"
#include "duerme.h"
#include "azar.h"
#include "colores.h"
#include <string.h>
#include "mesa.h"
main()
{
	int final,p_nj, p_nf;	
	tpartida pa;
	
	char pregunta_humano[30]="Un jugador humano?";
	char pregunta_omniconsciencia[30]="Quieres omniconsciencia?";
	char pregunta_rango[30]="¿Numero de jugadores?";
	int i, j;
	
	printf_color(3);
	printf("PROGRAMA REALIZADO POR: Albert Poblador, Pau Rodriguez, Raul Perez.");
	scanf("%*c");
	printf("\n");
	printf("AGRADECIMIENTOS:");
	scanf("%*c");
	printf("A Eva Rodriguez, por su gran ayuda, paciencia y debugador.");
	scanf("%*c");
	printf("A Marc Sarri, companyero fiel. Va por ti.");
	scanf("%*c");
	printf("A la maquina de cafe del A2.");
	scanf("%*c");
	printf("COMIENZA EL JUEGO!!!");
	scanf("%*c");
	printf("\n\n\n");
	pa.js.n_jugadores = preguntar_n_en_rango(pregunta_rango, 2, 4);
	pa.js.un_humano = preguntar_si_o_no(pregunta_humano);
	pa.visible = preguntar_si_o_no(pregunta_omniconsciencia);
	printf_color(-1);
	
	inicializar_partida(&pa);
	imprimir_estado_partida(pa);
	
	while (final != TRUE)
	{
		imprimir_estado_partida(pa);
		realizar_jugada(&pa);
		final = se_ha_acabado_la_partida(pa);
		pa.js.turno++;
		if(pa.js.turno==pa.js.n_jugadores)
			pa.js.turno=0;
		duerme_n_segundos(1);
		
	}
	if(pa.js.turno==0)
	{
		pa.js.turno=pa.js.n_jugadores;
	}
	else
	{
		pa.js.turno--;
	}
	
	
	finalizar_partida(pa);
	
}
