#ifndef PARSEFILE_H
#define PARSEFILE_H


class ParseFile
{
    public:
        ParseFile(string File);
        virtual ~ParseFile();
        map<unsigned int, unsigned int> retrieveTowers();

    protected:

    private:
};

#endif // PARSEFILE_H
