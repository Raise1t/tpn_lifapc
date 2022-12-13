#include "librairie.h"

using namespace std;

Librairie::Librairie() {
    ligne = rand() % 10;
    colonne = rand() % 10;
}

Librairie::Librairie(int l, int c) {
    ligne = l;
    colonne = c;
}

void Librairie::dijkstra(const Terrain& terrain) {
    Sommet** noir = new Sommet*[terrain.obtenirDernierIndice()+1];
    Sommet** gris = new Sommet*[terrain.obtenirDernierIndice()+1];
    Sommet** blanc= new Sommet*[terrain.obtenirDernierIndice()+1];

    distances = new Sommet[terrain.obtenirDernierIndice()+1];
    int indiceLibrairie = terrain.obtenirIndice(ligne, colonne);
    int* voisins = terrain.obtenirTousVoisins(indiceLibrairie);

    for (int i = 0; i <= terrain.obtenirDernierIndice(); i++) {
        if (i != voisins[0] && i != voisins[1] && i != voisins[2] && i != voisins[3]) {
            blanc[i] = new Sommet(i, -1, 0);
        } else {
            gris[i] = new Sommet(
                i,
                sqrt(1 + pow(terrain.obtenirAltitude(indiceLibrairie) - terrain.obtenirAltitude(i), 2)),
                indiceLibrairie
            );
        }
    }

    noir[indiceLibrairie] = gris[indiceLibrairie];
    gris[indiceLibrairie] = nullptr;

    bool testGris = true;
    while (testGris) {
        int min = -1;
        int nmin = -1;
        for (int i = 0; i < terrain.obtenirDernierIndice(); i++) {
            Sommet* s = gris[i];
            if (s->obtenirDistance() < min || min == -1) {
                min = s->obtenirDistance();
                nmin = s->obtenirIndice();
            }
        }

        voisins = terrain.obtenirTousVoisins(nmin);
        for (int i = 0; i < 4; i++) {
            if (!noir[voisins[i]]) {
                if(blanc[voisins[i]]) {
                    gris[voisins[i]] = blanc[voisins[i]];
                    blanc[voisins[i]] = nullptr;
                }

                if (
                    gris[nmin]->obtenirDistance()
                    +
                    sqrt(1 + pow(terrain.obtenirAltitude(nmin) - terrain.obtenirAltitude(voisins[i]), 2))
                    <
                    gris[voisins[i]]->obtenirDistance()
                ) {
                    gris[voisins[i]]->modifierDistance(gris[nmin]->obtenirDistance() + sqrt(1 + pow(terrain.obtenirAltitude(nmin) - terrain.obtenirAltitude(voisins[i]), 2)));
                    gris[voisins[i]]->modifierPredecesseur(nmin);
                }
            }
        }

        noir[nmin] = gris[nmin];
        gris[nmin] = nullptr;
    }
}
