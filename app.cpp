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
