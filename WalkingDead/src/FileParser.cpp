#include "FileParser.h"

FileParser::FileParser(string file)
{
    this->file = file;
}

FileParser::~FileParser()
{
    //dtor
}

map<int, int> FileParser::retrieveTowers() {
    map<int, int> towers; // Map distance-estimation des tours

    ifstream flux(this->file.c_str());
    string delimiter = "\t"; // Délimiteur entre la distance et l'estimation

    if (flux) {
        string ligne;
        int i = 0;

        while (getline(flux, ligne)) {
            if (i > 1) { // Les deux premières lignes représentent le nombre de tireurs et de tours
                string distanceStr = ligne.substr(0, ligne.find(delimiter));
                ligne.erase(0, ligne.find(delimiter) + delimiter.length());
                string estimateStr = ligne.substr(0, ligne.find(delimiter));

                int distance = atoi(distanceStr.c_str());
                int estimate = atoi(estimateStr.c_str());

                towers[distance] = estimate;
            }

            i++;
        }
    } else {
        cout << "Impossible d'ouvrir le fichier " << this->file << endl;
    }
    flux.close();

    return towers;
}

int FileParser::retrieveNbShooters() {
    int shooters = 0;

    ifstream flux(this->file.c_str());

    if (flux) {
        string ligne1;
        getline(flux, ligne1);
        shooters = atoi(ligne1.c_str());
    } else {
        cout << "Impossible d'ouvrir le fichier " << this->file << endl;
    }

    return shooters;
}

int FileParser::retrieveNbTowers() {
    int towers = 0;

    ifstream flux(this->file.c_str());

    if (flux) {
        string ligne2;
        getline(flux, ligne2);
        getline(flux, ligne2);
        towers = atoi(ligne2.c_str());
    } else {
        cout << "Impossible d'ouvrir le fichier " << this->file << endl;
    }

    return towers;
}
