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

#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED

#include"includes.h"
#include"app.h"

class Anim
{
    public:
    Anim()
    {
        w=0;
        h=0;
    }
    void loadImage(char *file);
    void printImage(App a,int x,int y,int w1=0,int h1=0,int w2=0,int h2=0);
    float getH()
    {
        return h;
    }
    float getW()
    {
        return w;
    }
    protected:
    sf::Image image;
    sf::Sprite sprite;
    float h;
    float w;
};

#endif // ANIMATION_H_INCLUDED
