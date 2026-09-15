#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "graphe.h"


void initialiser_graphe(FILE* f, graphe *g) {
    
    char buffer[256];
    int u, v, w;

    fscanf(f, "n_sommets %zu", &g->n_sommets);
    fgets(buffer, sizeof(buffer), f); // Lire la fin de ligne
     
    int oriente;
    fscanf(f, "oriente %d", &oriente);
    g->oriente = (bool)oriente;
    fgets(buffer, sizeof(buffer), f);
    
    int value;
    fscanf(f, "value %d", &value);
    g->value = (bool)value;
    fgets(buffer, sizeof(buffer), f);
    
    g->l_adj = malloc(g->n_sommets * sizeof(*g->l_adj));
    for (size_t i = 0; i < g->n_sommets; i++) {
        initialiser_liste(&g->l_adj[i]);
    }
    
    fscanf(f, "%s", buffer); // DEBUT_DEF_ARETES
    g->n_aretes = 0;
    while (fscanf(f, "%s", buffer) != EOF) {
        if (strcmp(buffer, "FIN_DEF_ARETES") == 0) {
            break;
        }
        
        u = atoi(buffer);
        fscanf(f, "%d", &v);
        
        if (g->value) {
            fscanf(f, "%d", &w);
        } 
        
        // Créer une cellule pour v dans la liste d'adjacence de u
        cellule *c = malloc(sizeof(cellule));
        initialiser_cellule(c, v,w);
        inserer_liste(&g->l_adj[u], c);
        
        g->n_aretes++;
        
        //Si le graphe est non orienté, ajouter l'arête inverse
        if (!g->oriente) {
            cellule *c2 = (cellule *)malloc(sizeof(cellule));
            initialiser_cellule(c2, u, w);
            inserer_liste(&g->l_adj[v], c2);
            // g->n_aretes++;
        }
    }
    
    g->m_stockage = malloc(g->n_sommets * g->n_sommets * sizeof(*g->m_stockage));
    g->m_adj = malloc(g->n_sommets * sizeof(*g->m_adj));
    for (size_t i = 0; i < g->n_sommets; ++i)
        g->m_adj[i] = g->m_stockage + g->n_sommets * i;
    
    // Initialiser la matrice à 0
    for (size_t i = 0; i < g->n_sommets * g->n_sommets; i++) {
        g->m_stockage[i] = 0;
    }
    
    // Remplir la matrice d'adjacences à partir des listes d'adjacences
    for (size_t i = 0; i < g->n_sommets; i++) {
        cellule *courant = g->l_adj[i].tete;
        while (courant != NULL) {
            g->m_adj[i][courant->id_sommet] = courant->poids;
            courant = courant->succ;
        }
    }
    
}
void afficher_graphe(graphe g) {
    printf("Nombre de sommets %zu \n",g.n_sommets);
    if(!g.oriente) {
        printf("Non oriente\n");
    }
    else {
        printf("Oriente\n");
    }
     if(!g.value) {
        printf("Non value\n");
    }
    else {
        printf("value\n");
    }
    printf("Listes d'adjacences: \n");
    for(size_t i = 0; i < g.n_sommets; i++) {
        printf("%zu --> ", i);
        afficher_liste(g.l_adj[i]);
    }
    printf("Matrice d'adjacences: \n");

    for(size_t i = 0; i < g.n_sommets; i++) {
        for(size_t j = 0; j < g.n_sommets; j++) {
            printf("%d ", g.m_adj[i][j]);
        }
        printf("\n");
    }
}
void detruire_graphe(graphe *g) {
    // Détruire les listes d'adjacences
    for(size_t i = 0; i < g->n_sommets; i++) {
        cellule *courant = g->l_adj[i].tete;
        cellule *suivant;
        while(courant != NULL) {
            suivant = courant->succ;
            free(courant);
            courant = suivant;
        }
    }
    
    // Libérer le tableau de listes
    free(g->l_adj);
    // Libérer la matrice d'adjacences
    free(g->m_adj);
    free(g->m_stockage);
    
}