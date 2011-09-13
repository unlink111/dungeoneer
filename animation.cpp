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
