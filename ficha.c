/* En este archivo .c encontraremos todos las funciones referentes a las fichas*/

#include <stdio.h>
#include "ficha.h"



tficha inicializar_ficha(int a, int b)
{
		tficha f;
		f.a=a;
		f.b=b;
		return f;
}


void girar_ficha(tficha *f)
{
	int aux;

		aux=f->a;
		f->a=f->b;
		f->b=aux;
}

void printar_ficha(tficha f, int visible)
{
	
	if(visible==TRUE)
	{
	  printf("%d:%d|", f.a, f.b);
	}
	
	if(visible==FALSE)
	{
	  printf("?:?|");
	}
	
}

void ficha_2D(tficha f)
{
	//extra
}

int comprobar_doble(tficha f)
{
	if(f.a==f.b)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}	

