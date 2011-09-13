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
