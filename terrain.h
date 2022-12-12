#include <iostream>
#include <string>
#include <cstdio>
#include <fstream> //ifstream, ofstream
#include <cstdlib> //exit
#include "enumeration.h" //Direction

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

    int obtenirIndice(int i, int j);
    int obtenirColonne(int indice);
    int obtenirLigne(int indice);
    int obtenirAltitude(int indice) const;
    int obtenirVoisin(Direction dir, int indice);
    int* obtenirTousVoisins(int indice);

    void modifierAltitude(int indice, unsigned int nouvelleAltitude);
    void afficher();

    void exporter();
    void remplir();
    bool voisinExiste() const;
};
