#include "tas.h"
#include <stdlib.h>

void initialiser_tas(tas *t, size_t longueur) {
    t->longueur = longueur;
    t->taille = 0;
    t->tab_aretes = malloc(longueur * sizeof(arete));
}

void construire_tas(arete *a, size_t n, tas *t) {
    for (size_t i = 0; i < n; i++) {
        t->tab_aretes[i] = a[i];
    }
    t->taille = n;
    for (int i = (int)(n / 2) - 1; i >= 0; i--) {
        entasser_max(t, (size_t)i);
    }
}
void afficher_tas(tas t) {
    printf("longueur : %zu - taille : %zu\n", t.longueur, t.taille);
    for (size_t i = 0; i < t.taille; i++) {
        printf("indice : %zu - i :  %d - j : %d - poids : %d\n", i, t.tab_aretes[i].i, t.tab_aretes[i].j, t.tab_aretes[i].poids);
    }
}
size_t parent(size_t i) {
    return (i - 1) / 2;
}

size_t gauche(size_t i) {
    return 2 * i + 1;
}

size_t droite(size_t i) {
    return 2 * i + 2;
}

void entasser_max(tas *t, size_t i) {
    size_t g = gauche(i);
    size_t d = droite(i);

    size_t max;

    if (g < t->taille && t->tab_aretes[g].poids > t->tab_aretes[i].poids) {
        max = g;
    }
    else {
        max = i;
    }
    if (d < t->taille && t->tab_aretes[d].poids > t->tab_aretes[max].poids) {
        max = d;
    }
    if (max != i) {
        arete temp = t->tab_aretes[i];
        t->tab_aretes[i] = t->tab_aretes[max];
        t->tab_aretes[max] = temp;
        entasser_max(t, max);
    }
}

void detruire_tas(tas *t) {
	free(t->tab_aretes);
	t->tab_aretes = NULL;
	t->longueur = 0;
	t->taille = 0;
}