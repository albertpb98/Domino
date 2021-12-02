#ifndef FICHA_H
#define FICHA_H

#define FALSE	0
#define TRUE	1

#define NUM_FICHAS_DOMINO 28

typedef struct {
	int a,b;	// Los dos nums de la ficha
}tficha;

tficha inicializar_ficha(int a, int b);
void girar_ficha(tficha *f);
void printar_ficha(tficha f, int visible);
int comprobar_doble(tficha f);
void ficha_2D(tficha f);

#endif // FICHA_H

