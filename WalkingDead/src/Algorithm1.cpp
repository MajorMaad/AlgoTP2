#include "Algorithm1.h"

Algorithm1::Algorithm1(string file)
{
    this->file = file;
    FileParser fp(file);
    this->nbShooters = fp.retrieveNbShooters();
    this->nbTowers = fp.retrieveNbTowers();
    this->towers = fp.retrieveTowers();
}

Algorithm1::~Algorithm1()
{
    //dtor
}

vector<int> Algorithm1::positionShooters() {
    vector<int> shootersPlaced(nbShooters, 0); // Tableau contenant les numéros des tours sur lesquelles placer un tireur

    map<int, pair<int, int> > towersCopy;
    towersCopy.insert(this->towers.begin(), this->towers.end());

    int i = this->nbShooters;
    while (i!= 0) {
        int index = -1;
        int maxEstimate = -1;
        int distance = -1;

        // On récupère le numéro de la tour ayant la plus grande estimation, puis on la retire de la map
        map<int, pair<int, int> >::iterator p;
        for (p = towersCopy.begin(); p!= towersCopy.end(); p++) {
            if (p->second.second > maxEstimate) {
                maxEstimate = p->second.second;
                index = p->first;
            }
        }

        shootersPlaced[this->nbShooters-i] = index;
        towersCopy.erase(index);
        i--;
    }

    return shootersPlaced;
}

void Algorithm1::displayResult() {
    vector<int> positions = positionShooters();
    int i = 1;

    for(vector<int>::iterator it = positions.begin(); it != positions.end(); it++) {
        int index = *it;
        cout << "Tireur n°" << i++ << " se place à la tour n°" << index << " à une distance " << this->towers[index].first << endl;
    }
}
