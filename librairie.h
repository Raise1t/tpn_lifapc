#include <math.h>
#include "terrain.h"
#include "sommet.h"
#include "enumeration.h"

class librairie {
private:
    int ligne;
    int colonne;
    Sommet* distances;

public:
    librairie();
    librairie(int l, int c);
    ~librairie();

    void dijkstra(const Terrain& terrain);
};
