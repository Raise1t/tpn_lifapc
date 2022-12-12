#include "enumeration.h" //Couleur

class sommet {
private:
    int indice;
    int distance;
    int predecesseur;

public:
    sommet();
    sommet(int i);
    sommet(int i, int dist, int pred, Couleur coul);

    int obtenirIndice() const;
    int obtenirDistance() const;
    int obtenirPredecesseur() const;

    void modifierIndice(int i);
    void modifierDistance(int dist);
    void modifierPredecesseur(int pred);
};
