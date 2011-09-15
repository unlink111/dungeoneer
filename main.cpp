/*
<dungeoneer a multiplayer action role playing game> Version 0.0.1
(C) 2011 Lukas Krickl (Programming,Level Design,Sound), Franz Sperl (Level Design,Story,Sound)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
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
    return "<dungeoneer a multiplayer action role playing game> Version 0.0.1\n(C) 2011 Lukas Krickl (Programming,Level Design,Sound), Franz Sperl (Level Design,Story,Sound)\nThis program is free software: you can redistribute it and/or modify\nit under the terms of the GNU General Public License as published by\nthe Free Software Foundation, either version 3 of the License, or\n(at your option) any later version.\n\nThis program is distributed in the hope that it will be useful,\nbut WITHOUT ANY WARRANTY; without even the implied warranty of\nMERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\nGNU General Public License for more details.\n\nYou should have received a copy of the GNU General Public License\nalong with this program.  If not, see <http://www.gnu.org/licenses/>.";
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
