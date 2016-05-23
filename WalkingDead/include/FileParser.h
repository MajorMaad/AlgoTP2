#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <stdlib.h>

#include <string>
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

class FileParser
{
    public:
        FileParser(string file);
        virtual ~FileParser();
        map<int, pair<int, int> > retrieveTowers();
        int retrieveNbShooters();
        int retrieveNbTowers();

    protected:

    private:
        string file;
};

#endif // FILEPARSER_H
