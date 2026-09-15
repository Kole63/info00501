#include "cellule.h"
#include <stdlib.h>

void initialiser_cellule(cellule *c, int id_sommet, int poids) {
    c->pred = c->succ = NULL;
    c->id_sommet = id_sommet;
    c->poids = poids;
}

