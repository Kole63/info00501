#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "ensembles.h"


void creer_ensemble(ensembles *x,int i) {
        x->parent[i] = i;
        x->rang[i] = 0; 
}
ensembles* initialiser_ensembles(size_t t) {
    ensembles *x = malloc(sizeof(ensembles));
    x->taille = t;
    x->parent = malloc(t*sizeof(int));
    x->rang = malloc(t*sizeof(int));
    for(size_t i = 0; i < t; i++) {
        creer_ensemble(x, i);
    }
    
    return x;
}
void afficher_ensembles(ensembles e) {
    printf("Parent\t");
    for(size_t i = 0; i < e.taille; i++) {
        printf("%d ",e.parent[i]);
    }
    printf("\n");
    printf("Rang\t");
    for(size_t i = 0; i < e.taille; i++) {
        printf("%d ",e.rang[i]);
    }
    printf("\n");

}

void remplir_ensembles_comme_tp(ensembles* e) {
    int t_parent[12] = {4, 2, 2, 2,4, 5,2,7,4,5,10,10};
    int t_rang[12]   = {0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0};
	for(size_t i = 0; i < e->taille; i++) {
		e->parent[i] = t_parent[i];
		e->rang[i] = t_rang[i];
	}
}

int trouver_ensemles(ensembles *e, int valeur) {
    int racine = valeur;
    while(e->parent[racine - 1 ] != racine) {
        racine = e->parent[racine - 1];
    }
    while(valeur != racine) {
        int p = e->parent[valeur - 1];
        e->parent[valeur - 1] = racine;
        valeur = p;
    }
    return racine;
}


void union_ensembles(ensembles *e, int x,int  y) {
    int racine_x = trouver_ensemles(e,x);
    int racine_y = trouver_ensemles(e,y);

    printf("racine de %d : %d racine de %d : %d\n",x, racine_x,y, racine_y);
    if(racine_x != racine_y) {
        if(e->rang[racine_x] < e->rang[racine_y]) {
            e->parent[racine_x] = racine_y;
        }
        else {
            if(e->rang[racine_x] > e->rang[racine_y]) {
                e->parent[racine_y] = racine_x;
            }
            else {
                e->parent[racine_y] = racine_x;
                e->rang[racine_x] = e->rang[racine_x] + 1;
            }
        }
    } else {
        printf("Ne marche pas\n");
    }
}