/*
    This file is part of dungeoneer.

    dungeoneer is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    dungeoneer is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/

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
    string theme;
    char file[max];
};


#endif // MAP_H_INCLUDED
