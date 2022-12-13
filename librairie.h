#include <math.h>
#include "terrain.h"
#include "sommet.h"

class Librairie {
private:
    int ligne;
    int colonne;
    Sommet* distances;

public:
    Librairie();
    Librairie(int l, int c);

    void dijkstra(const Terrain& terrain);
};
