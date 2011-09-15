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

#include"app.h"
#include"map.h"

void App::startApp()
{
    running=true;
    win.Create(sf::VideoMode(800,600,32),"dungeoneer");
    this->load();

    while(running)
    {
        this->event();
        win.Clear();
        win.Display();
    }
}

void App::event()
{
    while(win.GetEvent(e))
    {
        if(e.Type==sf::Event::Closed)
        {
            running=false;
        }
        if((e.Type==sf::Event::KeyPressed)&&(e.Key.Code==sf::Key::Escape))
        {
            running=false;
        }
    }
}

void App::render()
{

}

void App::load()
{
    LoadMap map((char*)"Test",this);
}
