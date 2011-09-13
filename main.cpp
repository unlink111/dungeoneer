/*
<dungeoneer a multiplayer action role playing game> Version 0.0.1
(C) 2011 Lukas Krickl (Programming,Level Design,Sound), Franz Sperl (Level Design,Story,Sound)
*/


#include"main.h"

void Main::checkArgs(int argc,char *argv[])
{
    for(int i=1;i<argc;i++)
    {
        if(!strncmp(argv[i],"-h",max))
        {
            cout<<this->help();
        }
        else
        {
            cerr<<this->err(string(argv[i]));
        }
    }
}

string Main::help()
{
    return "<dungeoneer a multiplayer action role playing game> Version 0.0.1\n(C) 2011 Lukas Krickl (Programming,Level Design,Sound), Franz Sperl (Level Design,Story,Sound)\n";
}
string Main::err(string arg)
{
    string ret="No such argument: "+arg+"\nTry -h for help\n";
    return ret;
}

int main(int argc,char *argv[])
{
    Main *m=new Main;
    m->checkArgs(argc,argv);
    delete m;

    App *app=new App;

    app->startApp();

    return 0;
}
