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
