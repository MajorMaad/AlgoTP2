#include <iostream>
#include "FileParser.h"

using namespace std;

int main()
{
    // Test file parser
    FileParser fp("fichiers-test/T_7_30.txt");

    // Test recuperation des tours
    map<int, int> towers = fp.retrieveTowers();

    map<int, int>::iterator p;

    for (p = towers.begin(); p!= towers.end(); p++) {
        cout << "Distance : " << p->first << " --- Estimation : " << p->second << endl;
    }

    // Test recuperation du nombre de tireurs
    int nbShooters = fp.retrieveNbShooters();
    cout << "Nombre de tireurs : " << nbShooters << endl;

    // Test recuperation du nombre de tours
    int nbTowers = fp.retrieveNbTowers();
    cout << "Nombre de tours : " << nbTowers << endl;

    return 0;
}
