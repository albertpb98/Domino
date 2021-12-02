#include <stdio.h>
#include "tirada.h"

void imprimir_tirada(ttirada t, tjugador j)
{
	printf_color(2);
	printf ("Tira:");
	printf ("%c%d:%d|\n", t.extremo, j.f[t.n_ficha].a, j.f[t.n_ficha].b);
	printf_reset_color();
}

void imprimir_tiradas(ttiradas posibles, tjugador j)
{
	int i, visibles = TRUE;

	printf_color(2);
	printf("Tiradas posibles: ");
	for(i=0; i<posibles.n_tiradas; i++)
	{
		printf("%d(%c",i, posibles.t[i].extremo);
		printar_ficha(j.f[posibles.t[i].n_ficha], visibles);
		printf(") ");	
	}
	printf("\n");
	printf_reset_color();
}

ttiradas calcular_tiradas_posibles(tjugador j, tmesa m)
{
	ttiradas posibles;
	int k=0, left, right, i;

	 	left=extremo_izquierdo(m);
	 	right=extremo_derecho(m);
	 
	 		for(i=0; i<j.n_fichas; i++)
	 		{
	 			if(j.f[i].a==left)
	 			{
	 				posibles.t[k].girada=TRUE;
	 				posibles.t[k].n_ficha=i;
	 				posibles.t[k].extremo='i';
	 				k++;
	 			}
	 			
		 		if(j.f[i].b==left)
		 		{
		 			posibles.t[k].girada=FALSE;
		 			posibles.t[k].n_ficha=i;
		 			posibles.t[k].extremo='i';
		 			k++;
		 		}
		 			
		 		if(j.f[i].a==right)
			 	{
			 		posibles.t[k].girada=FALSE;
			 		posibles.t[k].n_ficha=i;
			 		posibles.t[k].extremo='d';
			 		k++;
			 	}
			 			
			 	if(j.f[i].b==right)
			 	{
			 		posibles.t[k].girada=TRUE;
			 		posibles.t[k].n_ficha=i;
			 		posibles.t[k].extremo='d';
			 		k++;
			 	}
			 	
			 }
				posibles.n_tiradas = k;
				return (posibles);
}
	 				
