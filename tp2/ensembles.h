#ifndef ENSEMBLE_H
#define ENSEMBLE_H

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

#endif