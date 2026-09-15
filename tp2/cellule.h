#ifndef CELLULE_H
#define CELLULE_H

typedef struct cellule_type {
	int id_sommet;
	int poids;
	struct cellule_type *pred;
	struct cellule_type *succ;
} cellule;

void initialiser_cellule(cellule *c, int id_sommet, int poids);
#endif