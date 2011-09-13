#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include"includes.h"
#include"app.h"
#include"file.h"
#include"map.h"

class Main
{
    public:
    void checkArgs(int argc,char *argv[]);
    string help();
    string err(string arg);
};

#endif // MAIN_H_INCLUDED
