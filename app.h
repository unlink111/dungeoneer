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
