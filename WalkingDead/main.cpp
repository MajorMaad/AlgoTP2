#include <iostream>
#include "FileParser.h"

using namespace std;

int main()
{
    // Test file parser
    FileParser fp("fichiers-test/T_7_30.txt");

    // Test recuperation des tours
    map<int, pair<int, int> > towers = fp.retrieveTowers();

    map<int, pair<int, int> >::iterator p;

    for (p = towers.begin(); p!= towers.end(); p++) {
        cout << "Tour n°" << p->first << " --- Distance : " << p->second.first << " --- Estimation : " << p->second.second << endl;
    }

    // Test recuperation du nombre de tireurs
    int nbShooters = fp.retrieveNbShooters();
    cout << "Nombre de tireurs : " << nbShooters << endl;

    // Test recuperation du nombre de tours
    int nbTowers = fp.retrieveNbTowers();
    cout << "Nombre de tours : " << nbTowers << endl;

    return 0;
}
