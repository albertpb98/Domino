/* En este archivo .c encontraremos todos las funciones referentes a la mesa*/

#include <stdio.h>
#include "mesa.h"


#define NUMF 28
#define FMAX 28
#define NUM_FICHAS_DOMINO 28


void inicializar_mesa (tmesa *m)
{
    m->n_fichas = 0;
}


void imprimir_mesa(tmesa m)
{
	int i;

	printf_color(0);
	printf("Mesa: ");
	for(i = 0; i < m.n_fichas; i++)
	{
		printf("%d:%d|", m.mesa[i].a, m.mesa[i].b);
	}
    printf("\n");
	printf_reset_color();
}


int extremo_izquierdo(tmesa m)
{
	
	return m.mesa[0].a;
}
	

int extremo_derecho(tmesa m)
{
	
	return m.mesa[m.n_fichas-1].b;
}


void pon_en_mesa_por_la_derecha(tmesa *m, tficha f)
{
        m->n_fichas = m->n_fichas+1;
	m->mesa[m->n_fichas-1].a = f.a;
	m->mesa[m->n_fichas-1].b = f.b;
        
}
	

void pon_en_mesa_por_la_izquierda(tmesa *m, tficha f)
{
    int i;

	
	for(i=(m->n_fichas); i > 0; i--)
	{
		m->mesa[i].a = m->mesa[i-1].a;
		m->mesa[i].b = m->mesa[i-1].b;
	}
	
	m->mesa[0].a = f.a;
	m->mesa[0].b = f.b;
        
        m->n_fichas = m->n_fichas+1;
}

	
	
