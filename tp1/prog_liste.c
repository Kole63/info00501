#include <stdio.h>
#include <stdlib.h>
#include "cellule.h"
#include "liste.h"
// #define TAILLE 5

// liste tab_listes[TAILLE]; Allocation statique

int main(void)
{
    liste l;
    size_t taille;
    int id_sommet, id_liste;
    // taille = 5;
    printf("Entrez la taille du  tableau: ");
    scanf("%zu", &taille);
    liste *tab_listes = malloc(sizeof(liste[taille]));
    for (int i = 0; i < taille; i++)
    {
        initialiser_liste(&tab_listes[i]);
    }
    for (int i = 0; i < taille; i++)
    {
        printf("Entrez l'indice de la liste (0 a %zu) et la valeur du sommet : ",
               taille - 1);
        scanf("%d %d", &id_liste, &id_sommet);

        // Vérification des bornes
        if (id_liste < 0 || id_liste >= taille)
        {
            printf("Indice de liste invalide !\n");
            i--; // on recommence cette itération
            continue;
        }

        cellule *c = malloc(sizeof(cellule));
        if (!c)
        {
            printf("Erreur d'allocation mémoire\n");
            exit(EXIT_FAILURE);
        }

        initialiser_cellule(c, id_sommet);
        inserer_liste(&tab_listes[id_liste], c);
    }
    for(int i = 0; i < taille; i++) {
        afficher_liste(tab_listes[i]);
    }
    cellule *c1 = malloc(sizeof(cellule));
    cellule *c3 = malloc(sizeof(cellule));
    cellule *c4 = malloc(sizeof(cellule));
    cellule *c2 = malloc(sizeof(cellule));
    initialiser_liste(&l);
    printf("Ajout de 4 sommets\n");
    printf("Entrez l'indice du sommet 1 : ");
    scanf("%d", &id_sommet);
    initialiser_cellule(c1, id_sommet);
    inserer_liste(&l, c1);
    // printf("id_sommet : %d - pred : (nil) - succ : (nil)\n",c1.id_sommet);
    // printf("Creation d'une cellule avec classe d'allocation dynamique\n");
    printf("Entrez l'indice du sommet 2 :");
    scanf("%d", &id_sommet);
    initialiser_cellule(c2, id_sommet);
    inserer_liste(&l, c2);
    // printf("id_sommet : %d - pred : (nil) - succ : (nil)",c2->id_sommet);
    printf("Entrez l'indice du sommet 3 : ");
    scanf("%d", &id_sommet);
    initialiser_cellule(c3, id_sommet);
    inserer_liste(&l, c3);
    printf("Entrez l'indice du sommet 4 : ");
    scanf("%d", &id_sommet);
    initialiser_cellule(c4, id_sommet);
    inserer_liste(&l, c4);
    afficher_liste(l);
    detruire_liste(&l);

    printf("Entrez l'indice du sommet a supprimer : 7 \n");
    if (rechercher_liste(l, 7) != NULL)
    {
        cellule *c = rechercher_liste(l, 7);
        supprimer_liste(&l, c);
        printf("Liste Obtenue\n");
        afficher_liste(l);
    }
    else
    {
        printf("Le sommet n'existe pas");
    }
    if (!NULL)
        afficher_liste(l);
    printf("l'indice du sommet a supprimer : 2 \n");
    if (rechercher_liste(l, 2) != NULL)
    {
        cellule *c = rechercher_liste(l, 2);
        supprimer_liste(&l, c);
        printf("Liste Obtenue\n");
        afficher_liste(l);
    }
    else
    {
        printf("Le sommet n'existe pas");
    }
    printf("l'indice du sommet a supprimer : 3 \n");
    if (rechercher_liste(l, 3) != NULL)
    {
        cellule *c = rechercher_liste(l, 3);
        supprimer_liste(&l, c);
        printf("Liste Obtenue\n");
        afficher_liste(l);
    }
    else
    {
        printf("Le sommet n'existe pas\n");
    }
    printf("l'indice du sommet a supprimer : 9 \n");
    if (rechercher_liste(l, 9) != NULL)
    {
        cellule *c = rechercher_liste(l, 9);
        supprimer_liste(&l, c);
        printf("Liste Obtenue\n");
        afficher_liste(l);
    }
    else
    {
        printf("Le sommet n'existe pas");
    }
    printf("l'indice du sommet a supprimer : 4 \n");
    if (rechercher_liste(l, 4) != NULL)
    {
        cellule *c = rechercher_liste(l, 4);
        supprimer_liste(&l, c);
        printf("Liste Obtenue\n");
        afficher_liste(l);
    }
    else
    {
        printf("Le sommet n'existe pas");
    }
    return EXIT_SUCCESS;
}