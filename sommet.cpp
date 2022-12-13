#include "sommet.h"

Sommet::Sommet() {
    indice = 0;
    distance = 0;
    predecesseur = 0;
}

Sommet::Sommet(int i) {
    indice = modifierIndice(0);
    distance = 0;
    predecesseur = 0;
}

Sommet::Sommet(int i, int dist, int pred) {
    indice = modifierIndice(i);
    distance = dist;
    predecesseur = modifierPredecesseur(pred);
}

int Sommet::obtenirIndice() const {
    return indice
}

int Sommet::obtenirDistance() const {
    return distance;
}

int Sommet::obtenirPredecesseur() const {
    return predecesseur;
}


void modifierIndice(int i) {
    if (i > 0)
        indice = i;
}

void Sommet::modifierDistance(int dist) {
    distance = dist;
}

void Sommet::modifierPredecesseur(int pred) {
    if (pred > 0)
        predecesseur = pred;
}
