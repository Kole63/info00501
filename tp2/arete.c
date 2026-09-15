#include "arete.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


arete* construire_arete(graphe *g) {
    arete *a = malloc(g->n_aretes * sizeof(*a));
    int index = 0;
    for(size_t i = 0; i < g->n_sommets; i++) {
        cellule *courant = g->l_adj[i].tete;
        while(courant != NULL) {
            if (g->oriente || i <= (size_t)courant->id_sommet) {
                a[index].i = i;
                a[index].j = courant->id_sommet;
                a[index].poids = courant->poids;
                index++;
            }
            courant = courant->succ; 
        }
    }
    return a;
}

void afficher_arete(size_t n_aretes, arete *a) {
    for(size_t i = 0; i < n_aretes; i++) {
        printf("(%d, %d) %d\n", a[i].i, a[i].j, a[i].poids);
    }
}