#include "tri.h"
#include "tas.h"

void tri_insertion(arete* a, size_t nombre_aretes) {
    for(size_t j = 1; j < nombre_aretes; j++) {
        arete key = a[j];
        int i = j - 1;
        while(i >= 0 && a[i].poids > key.poids) {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = key;
    }
}

void tri_par_tas(arete* a, size_t nombre_aretes) {
    // Créer un tas à partir du tableau d'arêtes
    tas t;
    initialiser_tas(&t, nombre_aretes);
    construire_tas(a, nombre_aretes, &t);

    // Extraire les éléments du tas pour obtenir le tableau trié
    for (size_t i = nombre_aretes; i > 0; i--) {
        a[i - 1] = t.tab_aretes[0]; // L'élément maximum est à la racine du tas
        t.tab_aretes[0] = t.tab_aretes[t.taille - 1]; // Remplacer la racine par le dernier élément
        t.taille--; // Réduire la taille du tas
        entasser_max(&t, 0); // Réorganiser le tas
    }

    detruire_tas(&t);
}