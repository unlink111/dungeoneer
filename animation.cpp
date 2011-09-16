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

#include"animation.h"

void Anim::loadImage(char *file)
{
    if(!image.LoadFromFile(file))
    {
        cerr<<file<<" no such file or directorry\n";
        exit(-1);
    }

    sprite.SetImage(image);
    sprite.GetSize().x;
    sprite.GetSize().y;
}


void Anim::printImage(App a,int x,int y,int w1,int h1,int w2,int h2)
{
    if(w2==0)
    {
        w2=this->w;
    }
    if(h2==0)
    {
        h2=this->h;
    }
    sprite.SetPosition(x,y);
    sprite.SetSubRect(sf::IntRect(w1,h1,w2,h2));
    a.win.Draw(sprite);
}
