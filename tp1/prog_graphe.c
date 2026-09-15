#include <stdlib.h>
#include <stdio.h>
#include "graphe.h"
#include "arete.h"
#include "tri.h"
#include "tas.h"
int main() {
    FILE *fichier;
    char filename[256];
    printf("Entrez le nom du fichier que vous voulez etudes son graphe\n");
    scanf("%s", filename);
    fichier = fopen(filename, "r");
    if (fichier == NULL) {
        perror("Impossible d'ouvrir le fichier");
        return EXIT_FAILURE;
    }
    graphe *g = (graphe *)malloc(sizeof(graphe));
    initialiser_graphe(fichier, g);
    fclose(fichier);
    // afficher_graphe(*g);
    arete* a = construire_arete(g);
    // afficher_arete(*g, a);
    // tri_insertion(a, g->n_aretes);
    // afficher_arete(g->n_aretes, a);

    tas *t = (tas *)malloc(sizeof(tas));
    initialiser_tas(t, g->n_aretes);
    construire_tas(a, g->n_aretes, t);
 
    afficher_tas(*t);

    tri_par_tas(a, g->n_aretes);
    printf("Après le tri par tas :\n");
    afficher_arete(g->n_aretes, a);
    detruire_tas(t);
    free(t);
    free(a);
    detruire_graphe(g);
    free(g);
    return EXIT_SUCCESS;
}