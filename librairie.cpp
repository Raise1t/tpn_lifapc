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
    vector<Sommet> noir;
    vector<Sommet> gris;
    vector<Sommet> blanc;

    distances = new Sommet[terrain->dernierIndice+1];
    int indiceLibrairie = terrain->obtenirIndice(ligne, colonne);
    int* voisins = terrain->obtenirTousVoisins(indiceLibrairie);

    for (int i = 0; i <= terrain->dernierIndice; i++) {
        if (i != voisins[0] && i != voisins[1] && i != voisins[2] && i != voisins[3]) {
            blanc.insert(i, new Sommet(i, -1, 0));
        } else {
            gris.insert(i, new Sommet(
                i,
                sqrt(1 + pow(terrain->obtenirAltitude(indiceLibrairie) - terrain->obtenirAltitude(i), 2)),
                predecesseur = indiceLibrairie
            ));
        }
    }

    noir.insert(indiceLibrairie, gris.at(indiceLibrairie));
    gris.erase(indiceLibrairie);

    while (gris.size() > 0) {
        int min = -1;
        int nmin = -1;
        for (Sommet & s : gris)) {
            if (s->distance < min || min == -1) {
                min = s->distance;
                nmin = s->indice;
            }
        }

        voisins = terrain->obtenirTousVoisins(nmin);
        for (int i = 0; i < 4; i++) {
            if (!noir.at(voisins[i])) {
                if(blanc.at(voisins[i])) {
                    gris.insert(voisins[i], blanc.at(voisins[i]));
                    blanc.erase(voisins[i]);
                }

                if (
                    gris.at(nmin)->distance
                    +
                    sqrt(1 + pow(terrain->obtenirAltitude(nmin) - terrain->obtenirAltitude(voisins[i]), 2))
                    <
                    gris.at(voisins[i])->distance
                ) {
                    gris.at(voisins[i])->modifierDistance(gris.at(nmin)->distance + sqrt(1 + pow(terrain->obtenirAltitude(nmin) - terrain->obtenirAltitude(voisins[i]), 2)));
                    gris.at(voisins[i])->predecesseur = nmin;
                }
            }
        }

        noir.insert(nmin, gris.at(nmin));
        gris.erase(nmin);
    }
}
