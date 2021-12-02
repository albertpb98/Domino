#include <stdio.h>
#include "partida.h"
#include "tirada.h"

void inicializar_partida(tpartida *pa) 
{
    int p_nj=0, p_nf=0, i, j, k;
    
    inicializar_azar();
	inicializar_pila(&pa->p);

	 for (i = 0; i < pa->js.n_jugadores; i++) 
     {
             pa->js.j[i].n_fichas=0;
             if(pa->js.un_humano==TRUE&&i==0)
                 pa->js.j[i].tipo=T_HUMANO;
             else
                 pa->js.j[i].tipo=T_ROBOT;
        for (j = 0; j < 7; j++) 
        {
            pa->js.j[i].f[j] = coger_ficha(&pa->p);
            pa->js.j[i].n_fichas++;
        }
     }
	que_jugador_tiene_doble_mas_alto(pa->js, &p_nj, &p_nf);
    inicializar_mesa(&(pa->m));
    pa->m.mesa[0]=pa->js.j[p_nj].f[p_nf];
    pa->m.n_fichas=1;
    for (k = p_nf; k < pa->js.j[p_nj].n_fichas - 1; k++) {
                pa->js.j[p_nj].f[k] = pa->js.j[p_nj].f[k + 1];
            }

            pa->js.j[p_nj].n_fichas = pa->js.j[p_nj].n_fichas - 1;
   pa->js.turno=p_nj+1;
   if(pa->js.turno==pa->js.n_jugadores)
			pa->js.turno=0;

   
}

void imprimir_estado_partida(tpartida pa) 
{
	printf("\n\n\n");
    imprimir_pila(pa.p, pa.visible);
    imprimir_mesa(pa.m);
    printar_jugadores(pa.js, pa.visible);
	imprimir_turno(pa.js);
}

void realizar_jugada(tpartida *pa) {
    int i = 0, k, elec;
    int turno = pa->js.turno;
    ttiradas posibles;

    posibles = calcular_tiradas_posibles(pa->js.j[pa->js.turno], pa->m);
    imprimir_tiradas(posibles, pa->js.j[pa->js.turno]);
    tficha fi, tirar;


    if (pa->js.j[pa->js.turno].tipo == T_HUMANO) {
        if (posibles.n_tiradas == 0 && pila_vacia(pa->p) == FALSE) {
            do {
                fi = coger_ficha(&pa->p);
                printf("Coges: ");
                printar_ficha(fi, pa->visible);
                printf("\n");
                posibles = calcular_tiradas_posibles(pa->js.j[pa->js.turno], pa->m);
                pa->js.j[pa->js.turno].f[pa->js.j[pa->js.turno].n_fichas]=fi;
                pa->js.j[pa->js.turno].n_fichas++;
                printar_jugadores(pa->js, pa->visible);
                imprimir_tiradas(posibles, pa->js.j[pa->js.turno]);
            } while (posibles.n_tiradas == 0 && pila_vacia(pa->p) == FALSE);

           
        }
        if (posibles.n_tiradas != 0) {
            do {
                printf("¿Que tirada juegas?: ");
                scanf("%d", &elec);
            } while (elec < 0 || elec > posibles.n_tiradas);



            if (posibles.t[elec].girada == TRUE) {
                girar_ficha(&pa->js.j[pa->js.turno].f[posibles.t[elec].n_ficha]);
            }

            if (posibles.t[elec].extremo == 'd') {
                pon_en_mesa_por_la_derecha(&pa->m, pa->js.j[pa->js.turno].f[posibles.t[elec].n_ficha]);
            }

            if (posibles.t[elec].extremo == 'i') {
                pon_en_mesa_por_la_izquierda(&pa->m, pa->js.j[pa->js.turno].f[posibles.t[elec].n_ficha]);
            }

            for (k =posibles.t[elec].n_ficha; k < pa->js.j[pa->js.turno].n_fichas - 1; k++) 
            {
                pa->js.j[pa->js.turno].f[k] = pa->js.j[pa->js.turno].f[k + 1];
            }

            pa->js.j[pa->js.turno].n_fichas = pa->js.j[pa->js.turno].n_fichas - 1;
			pa->pasadas=0;
			
        }
       

        else {
            pasar_turno(&pa->js);
            pa->pasadas++;
        }
  
    }

    if (pa->js.j[pa->js.turno].tipo == T_ROBOT) {

        if (posibles.n_tiradas == 0 && pila_vacia(pa->p) == FALSE) {
            do {
                fi=coger_ficha(&pa->p);
                printf_color(2);
                printf("Va a la pila :') ");
                printar_ficha(fi, pa->visible);
                printf("\n");
                pa->js.j[pa->js.turno].f[pa->js.j[pa->js.turno].n_fichas]=fi;
                pa->js.j[pa->js.turno].n_fichas++;
                printar_jugadores(pa->js, pa->visible);
                posibles = calcular_tiradas_posibles(pa->js.j[pa->js.turno], pa->m);

            } while (posibles.n_tiradas == 0 && pila_vacia(pa->p) == FALSE);
        }
        else {		
            if (posibles.t[0].girada == TRUE) {
                girar_ficha(&pa->js.j[pa->js.turno].f[posibles.t[0].n_ficha]);
            }

            if (posibles.t[0].extremo == 'd') {
                pon_en_mesa_por_la_derecha(&pa->m, pa->js.j[pa->js.turno].f[posibles.t[0].n_ficha]);
            }

            if (posibles.t[0].extremo == 'i') {
                pon_en_mesa_por_la_izquierda(&pa->m, pa->js.j[pa->js.turno].f[posibles.t[0].n_ficha]);
            }

            for (k = posibles.t[0].n_ficha; k < pa->js.j[pa->js.turno].n_fichas - 1; k++) {
                pa->js.j[pa->js.turno].f[k] = pa->js.j[pa->js.turno].f[k + 1];
            }

            pa->js.j[pa->js.turno].n_fichas = pa->js.j[pa->js.turno].n_fichas - 1;
            

            pa->pasadas=0;
            
            if((posibles.n_tiradas == 0 && pila_vacia(pa->p) == TRUE)) {
            pasar_turno(&pa->js);
            pa->pasadas++;
            
        }



        }

    }
    
    	
}

void finalizar_partida(tpartida pa) {
	
    if (pa.pasadas == pa.js.n_jugadores) {
        printf("===>>> JUEGO BLOQUEADO! :-| <<<===\n\n\n");
        imprimir_pila(pa.p, pa.visible);
        imprimir_mesa(pa.m);
        printar_jugadores(pa.js, pa.visible);
    }
    else {
        if (pa.js.j[pa.js.turno].tipo == T_HUMANO) {
            printf("===>>> HAS GANADO! :-) <<<===\n\n\n");
            imprimir_pila(pa.p, pa.visible);
            imprimir_mesa(pa.m);
            printar_jugadores(pa.js, pa.visible);
        }
        else if (pa.js.j[pa.js.turno].tipo == T_ROBOT) {
            printf("===>>> HA GANADO EL J%d! :-/ <<<===\n\n\n", pa.js.turno);
            imprimir_pila(pa.p, pa.visible);
            imprimir_mesa(pa.m);
            printar_jugadores(pa.js, pa.visible);
        }
    }
}

int se_ha_acabado_la_partida(tpartida pa) {
    int finalizar;
    if (pa.js.j[pa.js.turno].n_fichas == 0 || pa.pasadas == pa.js.n_jugadores) {
        finalizar = TRUE;
    }
    else {
        finalizar = FALSE;
    }

    return finalizar;
}
