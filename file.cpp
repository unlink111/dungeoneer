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

#include"file.h"

////////////////////Load
List<string>* Load::load(char *file,int type)//type=0 == load with getine type=1 == load with f>>
{
    //first is true if the file is read for the first time
    bool first=true;
    string buf;
    ifstream f;
    f.open(file);
    if(f.is_open())
    {
        while(f.good())
        {
            //if the file is read for the first time it will create a new List opject in toLoad
            if(first)
            {
                first=false;
                if(type==0)
                {
                    getline(f,buf);
                }
                else if(type==1)
                {
                    f>>buf;
                }
                else
                {
                    cerr<<type<<": No such load type specified\n";
                }
                toLoad=new List<string>(buf);
            }
            else
            {
                if(type==0)
                {
                    getline(f,buf);
                }
                else if(type==1)
                {
                    f>>buf;
                }
                else
                {
                    cerr<<type<<": No such load type specified\n";
                }
                toLoad->add(buf);
            }
        }
        f.close();
    }
    else
    {
        cerr<<file<<" no such file or directorry\n";
    }
    return toLoad;
}

//////////////////////////Save
void Save::save(char *file,List<string> *toSave)
{
    ofstream f;
    f.open(file);
    if(f.is_open())
    {
        for(int i=0;i<toSave->getSize();i++)
        {
            f<<toSave->get(i)<<endl;
        }
        f.close();
    }
    else
    {
        cerr<<file<<" no such file or directorry\n";
    }
    f.close();
}
