#ifndef ENSEMBLE_H
#define ENSEMBLE_H
#include "graphe.h"
#include "tri.h"
#include "arete.h"


typedef struct {
	size_t taille;
	int *parent;
	int *rang;
} ensembles;

void creer_ensemble(ensembles *x, int i);
ensembles* initialiser_ensembles(size_t t);
void afficher_ensembles(ensembles e);
void remplir_ensembles_comme_tp(ensembles* e);
int trouver_ensemles(ensembles *e, int valeur);
void union_ensembles(ensembles *e, int x,int  y);
void detruire_ensembles(ensembles *e);
arete* acpm_kruskal_ensembles(graphe* g);
arete* acpm_kruskal_tableau(graphe *g);
void afficher_acpm(arete *a, size_t n_aretes);
#endif