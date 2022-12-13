class Sommet {
private:
    int indice;
    int distance;
    int predecesseur;

public:
    Sommet();
    Sommet(int i);
    Sommet(int i, int dist, int pred);

    int obtenirIndice() const;
    int obtenirDistance() const;
    int obtenirPredecesseur() const;

    void modifierIndice(int i);
    void modifierDistance(int dist);
    void modifierPredecesseur(int pred);
};
