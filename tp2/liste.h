#ifndef LISTE_H
#define LISTE_H
#include "cellule.h"
typedef struct {
    cellule *tete;
} liste;

void initialiser_liste(liste *l);
void inserer_liste(liste *l, cellule *c);
void afficher_liste(liste l);
cellule* rechercher_liste(liste l, int id_sommet);
void supprimer_liste(liste *l, cellule *c);
void detruire_liste(liste *l);

#endif