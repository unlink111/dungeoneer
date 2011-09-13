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
