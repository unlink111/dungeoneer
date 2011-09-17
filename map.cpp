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

//todo enemy object and npc class will be child classes of map and will load an print theyr seperately for now they will be loaded here

#include"map.h"

LoadMap::LoadMap(char *mapName,App *a)
{
    strncpy(file,mapName,max);
    strncat(file,"/for.lvl",max);
    mapFor=this->load(file);
    this->convMap(mapFor);

    strncpy(file,mapName,max);
    strncat(file,"/back.lvl",max);
    mapBack=this->load(file);
    this->convMap(mapBack);

    strncpy(file,mapName,max);
    strncat(file,"/obj.lvl",max);
    mapObj=this->load(file);
    this->convMap(mapObj);

    strncpy(file,mapName,max);
    strncat(file,"/enemy.lvl",max);
    mapEnemy=this->load(file);
    this->convMap(mapEnemy);

    strncpy(file,mapName,max);
    strncat(file,"/exit.lvl",max);
    mapExit=this->load(file);
    this->convMap(mapExit);
}

void LoadMap::convMap(List<string> *text,bool ignoreSpace,bool hit,bool damage)
{
    //buf1=text->get[i] buf2=the line that will be added to bufLst
    string buf,buf2;
    //temp list for this function
    List<string> bufLst;
    //==true if the char is not to be added
    bool notAdd=false;
    //filters spaces, blanke lines and comments in .lvl files for the convertion
    for(int i=0;i<text->getSize();i++)
    {
        buf=text->get(i);
        for(unsigned int j=0;j<=buf.size();j++)
        {
            if(buf[j]=='#')
            {
                //cerr<<mes<<"ignoring comment in list at "<<text<<endl;
                break;
            }
            else if((buf[j]==0) && ignoreSpace && !buf.empty())
            {
                //cerr<<mes<<"ignoring space in list at "<<text<<endl;
                continue;
            }
            else if(buf.empty())
            {
                //cerr<<mes<<"ignoring blank line in list at "<<text<<endl;
                notAdd=true;
                break;
            }
            else
            {
                //adds the char to buf2
                buf2=buf2+buf[j];
            }
        }
        if(notAdd)
        {
            notAdd=false;
        }
        else
        {
            bufLst.add(buf2);
            buf2.clear();
        }
    }
    //adds the infermation to the lists
    cerr<<endl<<endl;
    for(int i=0;i<bufLst.getSize();i++)
    {
        //cerr<<bufLst.get(i)<<endl;
        //enemy convertion
        if(bufLst.get(i)=="enemy")
        {
            bool enname=false;
            cerr<<mes<<"adding enemy to enemyList"<<endl;
            for(int j=i;j<bufLst.getSize();j++)
            {
                if(bufLst.get(j)=="spawn")
                {
                    cerr<<mes<<"setting spawn in enemyCord at ";
                    j++;
                    enemyCord.add(strToInt(bufLst.get(j)));
                    cerr<<bufLst.get(j)<<"/";
                    j++;
                    enemyCord.add(strToInt(bufLst.get(j)));
                    cerr<<bufLst.get(j)<<endl;
                    continue;
                }
                else if(bufLst.get(j)=="type")
                {
                    cerr<<mes<<"setting enemy type in enemyType "<<bufLst.get(++j)<<endl;
                    enemyType.add(bufLst.get(i));
                    continue;
                }
                else if(bufLst.get(j)=="name")
                {
                    cerr<<mes<<"Set enemy name to "<<bufLst.get(++j)<<endl;
                    //needs to be set when the enemy/npc class is written
                    enname=true;
                }
                else if(bufLst.get(j)=="end")
                {
                    if(!enname)
                        cerr<<warn<<"No enemy name specifide using type as name"<<endl;
                        //needs to be set wehn the enemy/npc class is written
                    cerr<<mes<<"ending editing enemy"<<endl;
                    i=j;
                    break;
                }
            }
        }
        else if(bufLst.get(i)=="exit")
        {
            cerr<<mes<<"beginning to set exit"<<endl;
            for(int j=i;j<bufLst.getSize();j++)
            {
                if(bufLst.get(j)=="tomap")
                {
                    cerr<<mes<<"setting exit to map "<<bufLst.get(++j)<<endl;
                    exitType.add(bufLst.get(j));
                    continue;
                }
                else if(bufLst.get(j)=="from")
                {
                    cerr<<mes<<"setting exit cordinates from "<<bufLst.get(++j);
                    exitCord.add(strToInt(bufLst.get(j)));
                    cerr<<" to "<<bufLst.get(++j)<<endl;
                    exitCord.add(strToInt(bufLst.get(j)));
                    continue;
                }
                else if(bufLst.get(j)=="to")
                {
                    cerr<<mes<<"setting exit cordinates to "<<bufLst.get(++j);
                    exitCord.add(strToInt(bufLst.get(j)));
                    cerr<<" to "<<bufLst.get(++j)<<endl;
                    exitCord.add(strToInt(bufLst.get(j)));
                    continue;
                }
                else if(bufLst.get(j)=="end")
                {
                    cerr<<mes<<"ending mapexit editing"<<endl;
                    i=j;
                    break;
                }
            }
        }
        else if(bufLst.get(i)=="theme")
        {
            for(int j=i;j<bufLst.getSize();j++)
            {
                cerr<<mes<<"Setting theme to "<<bufLst.get(++j)<<endl;
                this->theme=bufLst.get(j++);
                i=j;
                break;
            }
        }
        else if(bufLst.get(i)=="player")
        {
            //plazeholder for player spawn and name
            cerr<<mes<<"Starting editing player"<<endl;
            for(int j=i;i<bufLst.getSize();j++)
            {
                if(bufLst.get(j)=="end")
                {
                    cerr<<mes<<"Ending editing player"<<endl;
                    i=j;
                    break;
                }
            }
        }
        else if(bufLst.get(i)=="obj")
        {
            //plazeholder for object spawning
            cerr<<mes<<"Starting editing objects"<<endl;
            for(int j=i;i<bufLst.getSize();j++)
            {
                if(bufLst.get(j)=="end")
                {
                    cerr<<mes<<"Ending editing objects"<<endl;
                    i=j;
                    break;
                }
            }
        }
        else if(bufLst.get(i)=="forgr")
        {
            cerr<<mes<<"Starting editing forground"<<endl;
            for(int j=i;i<bufLst.getSize();j++)
            {
                if(bufLst.get(j)=="end")
                {
                    cerr<<mes<<"Ending editing forground"<<endl;
                    i=j;
                    break;
                }
            }
        }
        else if(bufLst.get(i)=="backgr")
        {
            cerr<<mes<<"Starting editing background"<<endl;
            for(int j=i;i<bufLst.getSize();j++)
            {
                if(bufLst.get(j)=="end")
                {
                    cerr<<mes<<"Ending editing background"<<endl;
                    i=j;
                    break;
                }
            }
        }
        else
        {
            cerr<<error<<"unknow map command: "<<bufLst.get(i)<<" in map "<<this->file<<endl;
        }
    }
    cout<<endl;
}

void LoadMap::printMap()
{

}

int LoadMap::strToInt(string str)
{
    int ret=0;
    char strBuf[max];
    //for function atoi
    for(unsigned int i=0;i<str.size();i++)
    {
        strBuf[i]=str[i];
    }
    ret=atoi(strBuf);//converts string to int

    return ret;
}
