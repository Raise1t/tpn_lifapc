#include "terrain.h"

using namespace std;

Terrain::Terrain() {
    // Construction par défaut :
    longueur = 10;
    largeur = 10;
    grille = new int[100];
    dernierIndice = 99;
    remplir();
}

Terrain::Terrain(int lon, int lar) {
    longueur = lon;
    largeur = lar;
    grille = new int[lon * lar];
    dernierIndice = longueur*largeur-1;
}

Terrain::Terrain(string fichierSource) {
    std::ifstream ifs;
    ifs.open(fichierSource);
    if(ifs.bad())
        {std::cout<<"Impossible d'ouvrir le fichier " << fichierSource << " en lecture \n"; exit(1);}
    
    ifs >> longueur;
    ifs >> largeur;
    grille = new int[longueur*largeur];
    
    int temp;
    int i = 0;
    while(ifs >> temp) {
        grille[i] = temp;
        i++;
    }

    ifs.close();

    dernierIndice = longueur*largeur-1;
}

Terrain::~Terrain() {
    delete grille;
}

void Terrain::operator=(const Terrain & copie) {
    longueur = copie.longueur;
    largeur = copie.largeur;
    grille = new int[longueur * largeur];

    for (int i = 0; i < obtenirIndice(longueur-1, largeur-1); i++)
    {
        grille[i] = copie.obtenirAltitude(i);
    }
    
}

int Terrain::obtenirIndice(int ligne, int colonne) {
    return ligne*largeur+colonne;
}

int Terrain::obtenirColonne(int indice) {
    return indice % largeur;
}

int Terrain::obtenirLigne(int indice) {
    return indice / largeur;
}

int Terrain::obtenirAltitude(int indice) const {
    return grille[indice];
}

int Terrain::obtenirVoisin(Direction dir, int indice) {
    int ligne = obtenirLigne(indice);
    int colonne = obtenirColonne(indice);

    switch (dir) {
        case NORD:
            if (ligne == 0)
                return -1;
            return obtenirIndice(ligne-1,colonne);
        case SUD:
            if (ligne == longueur-1)
                return -1;
            return obtenirIndice(ligne+1,colonne);
        case OUEST:
            if (colonne == 0)
                return -1;
            return obtenirIndice(ligne,colonne-1);
        case EST:
            if (colonne == largeur-1)
                return -1;
            return obtenirIndice(ligne,colonne+1);
        default:
            return -1;
    }
}

void Terrain::modifierAltitude(int indice, unsigned int nouvelleAltitude) {
    if (indice <= dernierIndice)
        grille[indice] = nouvelleAltitude;
}

void Terrain::afficher() {
    for (int i = 0; i < longueur; i++) {
        cout << "|  ";
        for (int j = 0; j < largeur; j++) {
            cout << (grille[i*largeur+j] > 9 ? "" : "0") << grille[i*largeur+j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void Terrain::exporter() {
    ofstream ofs;
    ofs.open("terrain");
    if(ofs.bad())
        {std::cout<<"Impossible d'ouvrir le fichier terrain en ecriture \n"; exit(1);}

    ofs << longueur << ' ' << largeur << endl;
    for (int i = 0; i <= dernierIndice; i++)
    {
        ofs << grille[i] << ' ';
    }
    ofs << endl;
    ofs.close();
}

void Terrain::remplir() {
    for (int i = 0; i <= dernierIndice; i++)
    {
        modifierAltitude(i, rand() % 100);
    }
}