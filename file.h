#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

#include"includes.h"

class Load
{
    public:
    List<string>* load(char *file,int type=0);
    private:
    List<string> *toLoad;
};

class Save
{
    public:
    void save(char *file,List<string> *toSave);
};

#endif // FILE_H_INCLUDED
