#include <stdlib.h>
#include "terrain.h"

using namespace std;

int main(int argc, char const *argv[])
{
    //Creation d'un terrain avec un constructeur par défaut
    Terrain terrain0;
    cout << "Terrain0 :" << endl;
    terrain0.afficher();

    Terrain terrain1(4,9);
    terrain1.remplir();
    cout << "Terrain1 :" << endl;
    terrain1.afficher();

    cout << "Altitude voisin nord 2,3 : "
        << terrain1.obtenirAltitude(terrain1.obtenirVoisin(NORD, terrain1.obtenirIndice(2,3)))
        << endl;
    
    cout << "Altitude voisin sud 3,3 : "
        << terrain1.obtenirAltitude(terrain1.obtenirVoisin(SUD, terrain1.obtenirIndice(3,3)))
        << endl;
    
    terrain1.exporter();

    Terrain terrain2("terrain");
    cout<< endl;
    terrain2.afficher();

    terrain2.modifierAltitude(16, 0);
    
    return 0;
}
