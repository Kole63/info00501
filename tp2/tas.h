#ifndef TAS_H
#define TAS_H
#include "arete.h"
typedef struct {
	size_t longueur;
	size_t taille;
	arete *tab_aretes;
} tas;


void initialiser_tas(tas *t, size_t longueur);
void construire_tas(arete *a, size_t n, tas *t);
void afficher_tas(tas t);
size_t parent(size_t i);
size_t gauche(size_t i);
size_t droite(size_t i);

//definir entasser_max
void entasser_max(tas *t, size_t i);

void detruire_tas(tas *t);

#endif