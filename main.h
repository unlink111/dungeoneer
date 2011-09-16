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
    along with dungeoneer.  If not, see <http://www.gnu.org/licenses/>.
*/

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
