#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include"includes.h"
#include"file.h"
#include"app.h"

class LoadMap:public Load
{
    public:
    //requeres App for printing on the main windows
    LoadMap(char *mapName,App *a);
    ~LoadMap()
    {
        delete mapFor;
        delete mapBack;
        delete mapObj;
        delete mapEnemy;
        delete mapExit;
        delete theme;
    }
    void printMap();//prints map
    void convMap(List<string> *text,bool ignoreSpace=true,bool hit=false,bool damage=false);//prepares loadet information for printing
    int strToInt(string str);

    private:
    List<string> *mapFor;//Map Forground
    List<string> *mapBack;//Map Background
    List<string> *mapObj;//Map Objects
    List<string> *mapEnemy;//Map Enemys
    List<string> *mapExit;//Cordinates for exiting the map

    List<string> hitType;
    List<int> hit;//hitbox
    List<string> exitType;
    List<int> exitCord;//exit Cordinates
    List<string> enemyType;
    List<int> enemyCord;
    List<string> objectType;
    List<int> objectCord;
    char *theme;
};


#endif // MAP_H_INCLUDED
