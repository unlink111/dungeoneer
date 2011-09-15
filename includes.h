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

#ifndef INCLUDES_H_INCLUDED
#define INCLUDES_H_INCLUDED

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<cstdio>

#include<SFML/Graphics.hpp>

#define max 99
#define warn "[WARNING]: "
#define mes "[MESSAGE]: "
#define error "[ERROR]: "
#define crit "[CRITICAL ERROR]: "

using namespace std;

template<class T>
class List
{
    public:
    List()
    {
    }
    List(T l)
    {
        this->add(l);
    }
    ~List()
    {
        lst.clear();
    }
    void add(T l)
    {
        lst.push_back(l);
    }
    void rem()
    {
        lst.pop_back();
    }
    T get(unsigned int i)
    {
        if(lst.size()>i)
        {
            return lst[i];
        }
        return lst[0];
    }

    int getSize()
    {
        return lst.size();
    }

    void getAll()
    {
        for(unsigned int i=0;i<lst.size();i++)
        {
            cout<<lst[i]<<endl;
        }
    }

    private:
    vector<T> lst;
};

#endif // INCLUDES_H_INCLUDED
