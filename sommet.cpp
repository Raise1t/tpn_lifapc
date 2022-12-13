#include "sommet.h"

Sommet::Sommet() {
    indice = 0;
    distance = 0;
    predecesseur = 0;
}

Sommet::Sommet(int i) {
    modifierIndice(0);
    distance = 0;
    predecesseur = 0;
}

Sommet::Sommet(int i, int dist, int pred) {
    modifierIndice(i);
    distance = dist;
    modifierPredecesseur(pred);
}

int Sommet::obtenirIndice() const {
    return indice;
}

int Sommet::obtenirDistance() const {
    return distance;
}

int Sommet::obtenirPredecesseur() const {
    return predecesseur;
}


void Sommet::modifierIndice(int i) {
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
