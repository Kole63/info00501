#ifndef GRAPHE_H
#define GRAPHE_H
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include "liste.h"
typedef struct {
	size_t n_sommets;
	size_t n_aretes;
	bool oriente;		/* false (0) si non oriente, true (1) si oriente */
	bool value;		/* false (0) si non value, true (1) si value */
	liste *l_adj;		/* listes d'adjacences */
	int **m_adj;		/* matrice d'adjacences */
	int *m_stockage;	/* tableau (1D) représentant une matrice d'adjacences (2D) */
} graphe;

void initialiser_graphe(FILE* f, graphe *g);
void afficher_graphe(graphe g);
void detruire_graphe(graphe *g);
#endif