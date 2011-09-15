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

#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED

#include"includes.h"
#include"file.h"

class App
{
    public:
    void startApp();
    void event();
    void load();
    void render();

    sf::RenderWindow win;
    private:
    bool running;
    sf::Event e;
};

#endif // APP_H_INCLUDED
