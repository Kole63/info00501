#ifndef ARETE_H
#define ARETE_H
#include "graphe.h"

typedef struct {
	int i;
	int j;
	int poids;
} arete;

arete* construire_arete(graphe *g);
void afficher_arete(size_t n_aretes, arete *a);
#endif
