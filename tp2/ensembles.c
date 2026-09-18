#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "ensembles.h"


void creer_ensemble(ensembles *x,int i) {
        x->parent[i] = i;
        x->rang[i] = 0; 
}
ensembles* initialiser_ensembles(size_t t) {
    ensembles *x = malloc(sizeof(ensembles));
    x->taille = t;
    x->parent = malloc(t*sizeof(int));
    x->rang = malloc(t*sizeof(int));
    for(size_t i = 0; i < t; i++) {
        creer_ensemble(x, i);
    }
    
    return x;
}
void afficher_ensembles(ensembles e) {
    printf("Parent\t");
    for(size_t i = 0; i < e.taille; i++) {
        printf("%d ",e.parent[i]);
    }
    printf("\n");
    printf("Rang\t");
    for(size_t i = 0; i < e.taille; i++) {
        printf("%d ",e.rang[i]);
    }
    printf("\n");

}

void remplir_ensembles_comme_tp(ensembles* e) {
    int t_parent[12] = {4, 2, 2, 2,4, 5,2,7,4,5,10,10};
    int t_rang[12]   = {0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0};
	for(size_t i = 0; i < e->taille; i++) {
		e->parent[i] = t_parent[i];
		e->rang[i] = t_rang[i];
	}
}

int trouver_ensemles(ensembles *e, int valeur) {
    int racine = valeur;
    while(e->parent[racine] != racine) {
        racine = e->parent[racine];
    }
    while(valeur != racine) {
        int p = e->parent[valeur];
        e->parent[valeur] = racine;
        valeur = p;
    }
    return racine;
}


void union_ensembles(ensembles *e, int x,int  y) {
    int racine_x = trouver_ensemles(e,x);
    int racine_y = trouver_ensemles(e,y);

    printf("racine de %d : %d racine de %d : %d\n",x, racine_x,y, racine_y);
    if(racine_x != racine_y) {
        if(e->rang[racine_x] < e->rang[racine_y]) {
            e->parent[racine_x] = racine_y;
        }
        else {
            if(e->rang[racine_x] > e->rang[racine_y]) {
                e->parent[racine_y] = racine_x;
            }
            else {
                e->parent[racine_y] = racine_x;
                e->rang[racine_x] = e->rang[racine_x] + 1;
            }
        }
    }
}

void detruire_ensembles(ensembles *e) {
    free(e->parent);
    free(e->rang);
    free(e);
}

arete* acpm_kruskal_ensembles(graphe* g) {
    arete *aretes = construire_arete(g);
    arete *acpm = malloc((g->n_sommets - 1) * sizeof(*acpm));
    ensembles *e = initialiser_ensembles(g->n_sommets);
    size_t n_acpm = 0;

    tri_par_tas(aretes, g->n_aretes);
    for (size_t i = 0; i < g->n_aretes && n_acpm < g->n_sommets - 1; i++) {
        int racine_i = trouver_ensemles(e, aretes[i].i);
        int racine_j = trouver_ensemles(e, aretes[i].j);
        if (racine_i != racine_j) {
            acpm[n_acpm] = aretes[i];
            n_acpm++;
            union_ensembles(e, racine_i, racine_j);
        }
    }

    detruire_ensembles(e);
    free(aretes);
    return acpm;

}


arete* acpm_kruskal_tableau(graphe *g) {
    arete *aretes = construire_arete(g);
    arete *acpm = malloc((g->n_sommets - 1) * sizeof(*acpm));
    int *cc = malloc(g->n_sommets * sizeof(*cc));
    size_t n_acpm = 0;

    tri_par_tas(aretes, g->n_aretes);

    for(size_t i = 0; i < g->n_sommets; i++) {
        cc[i] = i;
    }

    for(size_t i = 0; i < g->n_aretes && n_acpm < g->n_sommets - 1; i++) {
        int composante_i = cc[aretes[i].i];
        int composante_j = cc[aretes[i].j];

        if(composante_i != composante_j) {
            acpm[n_acpm] = aretes[i];
            n_acpm++;

            for(size_t j = 0; j < g->n_sommets; j++) {
                if(cc[j] == composante_j) {
                    cc[j] = composante_i;
                }
            }
        }
    }

    free(cc);
    free(aretes);
    return acpm;
}

void afficher_acpm(arete *a, size_t n_aretes) {
    printf("Arbre couvrant de poids minimal :\n");
    afficher_arete(n_aretes, a);
    int somme = 0;
    for(size_t i = 0; i < n_aretes; i++) {
        somme += a[i].poids;
    }
    printf("Poids de l'arbre : %d\n",somme);
}


