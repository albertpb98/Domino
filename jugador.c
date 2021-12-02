//Codigo de las funciones de jugadores

#include <stdio.h>
#include "jugador.h"
//#include "colores.h"

void print_jugador(tjugador j, int visible)
{ 
	int i;

 	if((visible == TRUE && j.tipo == 2) || j.tipo == 1)
 	{
 		for(i=0; i<j.n_fichas; i++)
 		{
 			printf("%d:%d|", j.f[i].a, j.f[i].b);
 		}
 	}
 	
 	if(visible == FALSE && j.tipo == 2)
 	{
 		for(i=0; i<j.n_fichas; i++)
 		{
 			printf("?:?|");
 		}
 	}
 	
}


void printar_jugadores(tjugadores js, int visible)
{ 
	int i;
	
    for (i=0; i<=js.n_jugadores-1; i++)
    {
       printf_color(1);
       printf ("J%d ", i);
       print_jugador(js.j[i], visible);
       if(js.j[i].tipo==T_HUMANO)
       		printf("Humano");
       else
       		printf("Robot");
       printf("\n");
       printf_reset_color();
    }
}


void que_jugador_tiene_doble_mas_alto(tjugadores js, int *p_nj, int *p_nf)
{
 	int doblemayor=-1, i, j;
 	*p_nf=0;
 	*p_nj=0;
 	for(i=0; i<js.n_jugadores; i++)
 	{
 		for(j=0; j<js.j[i].n_fichas; j++)
 		{
 			if(comprobar_doble(js.j[i].f[j])==TRUE)
 			{
 			   if (js.j[i].f[j].a>doblemayor) 
 			   {
 				 doblemayor=js.j[i].f[j].a;
                 *p_nj = i;
                 *p_nf = j;
 			   }
 			}
 		}
 	}
}

void pasar_turno(tjugadores *p_js)
{
	int turno=p_js->turno;
	
	printf_color(2);
    if (p_js->j[turno].tipo==T_HUMANO)
    {
      printf ("Pasas! :'(\n");
    }
    else
    {
      printf ("Pasa! :D\n");
    }
    printf ("\n");
    printf_reset_color();
    
}

void imprimir_turno(tjugadores j)
{
	printf_color(6);
  printf ("Turno: %d\n", j.turno);
   printf_reset_color();
}


