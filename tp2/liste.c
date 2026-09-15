#include <stdlib.h>
#include <stdio.h>
#include "liste.h"


void initialiser_liste(liste *l) {
    l->tete = NULL;
}
void inserer_liste(liste *l, cellule *c) {
    c->pred = NULL;
    c->succ = l->tete;
    if(l->tete != NULL) {
        l->tete->pred = c;
    }
    l->tete = c;
}
cellule* rechercher_liste(liste l, int id_sommet) {
    cellule *courant = l.tete;
    while(courant != NULL && courant->id_sommet != id_sommet) {
        courant = courant->succ;
    }
    return courant;
}
void supprimer_liste(liste *l, cellule *c) {
    if (c->pred != NULL ) {
        c->pred->succ = c->succ;
    }
    else {
        l->tete = c->succ;
    }
    if(c->succ != NULL) {
        c->succ->pred = c->pred;
    }
    free(c);
}
void detruire_liste(liste *l) {
    cellule *courant = l->tete;
    cellule *suivant;
    while(courant != NULL) {
        suivant = courant->succ;
        supprimer_liste(l, courant);
        courant = suivant;
    }
}
void afficher_liste(liste l) {
    cellule *c1 = l.tete;
    // printf("tete --> ");
    while(c1 != NULL) {
        printf("%d-%d ", c1->id_sommet, c1->poids);
        c1 = c1->succ;
    }
    printf("\n");
}

