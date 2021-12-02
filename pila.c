/* En este archivo .c encontraremos todos las funciones referentes a la pila*/

#include <stdio.h>
#include "pila.h"
//#include "azar.h"

void inicializar_pila(tpila *pi)
{
	int i, j, k = 0;
	tficha f;
	
	for(i = 0; i <= 6; i++)
	{
		for(j = 0; j < i+1; j++)
		{
			pi->f[k].a=i;
			pi->f[k].b=j;
			k++;
		}
	}
	pi->n_fichas=28;
}

void imprimir_pila(tpila pi, int visible)
{
	int i;
	
	
	printf_color(0);
	printf("Pila: ");
	if(visible == TRUE)
	{
		for(i=0; i < pi.n_fichas; i++)
		{
			printf("%d:%d|", pi.f[i].a, pi.f[i].b);
		}
		printf("\n");
	}
	
	if(visible == FALSE)
	{
		for(i = 0; i < pi.n_fichas; i++)
		{
			printf("?:?|");
		}
	}

	printf("\n");
	printf_reset_color();				

}


tficha coger_ficha(tpila *pi) 
{
	tficha cficha;
	int i, pos, j;	
	
	i = numero_al_azar(pi->n_fichas);
	cficha =pi->f[i];
	pos = i;
	
	for(j = pos; j < pi->n_fichas-1; j++)
	{
		pi->f[j]=pi->f[j+1];
	}	
		pi->n_fichas = pi->n_fichas-1;

	return cficha;
	
}

int pila_vacia(tpila pi)
{
		if(pi.n_fichas == 0)
		{
			return TRUE;
		}
		
		else
		{
			return FALSE;
		}
}
	


	
