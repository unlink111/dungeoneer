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
