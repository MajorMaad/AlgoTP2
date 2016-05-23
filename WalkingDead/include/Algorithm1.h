#ifndef ALGORITHM1_H
#define ALGORITHM1_H

#include <string>
#include <vector>
#include <map>

#include "FileParser.h"
using namespace std;

class Algorithm1
{
    public:
        Algorithm1(string file);
        virtual ~Algorithm1();
        vector<int> positionShooters();
        void displayResult();

    protected:

    private:
        string file;
        int nbShooters;
        int nbTowers;
        map<int, pair<int, int> > towers;
};

#endif // ALGORITHM1_H
