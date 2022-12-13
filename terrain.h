#include <iostream>
#include <string>
#include <cstdio>
#include <fstream> //ifstream, ofstream
#include <cstdlib> //exit

enum Direction { NORD, SUD, EST, OUEST };
inline Direction operator++ (Direction& d, int) {
    d = static_cast<Direction>((static_cast<int>(d) + 1) % 4);
    return d;
}

class Terrain {
private:
    int* grille;
    int longueur;
    int largeur;
    int dernierIndice;
public:
    Terrain();
    Terrain(int longueur, int largeur);
    Terrain(std::string fichierSource);
    ~Terrain();
    void operator=(const Terrain & copie);

    int obtenirIndice(int i, int j) const;
    int obtenirColonne(int indice) const;
    int obtenirLigne(int indice) const;
    int obtenirAltitude(int indice) const;
    int obtenirVoisin(Direction dir, int indice) const;
    int* obtenirTousVoisins(int indice) const;
    int obtenirDernierIndice() const;

    void modifierAltitude(int indice, unsigned int nouvelleAltitude);
    void afficher();

    void exporter();
    void remplir();
    bool voisinExiste(Direction dir, int indice) const;
};
