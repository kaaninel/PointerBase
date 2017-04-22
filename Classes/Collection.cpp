#pragma once
#include "../include.h"
#include "Set.cpp"

template <typename T>
class Collection : public Set<T>{
public:
    Collection() : Set<T>(){}
    ~Collection(){}

    T* Create(){
        T* tmp = new T();
        tmp->Update();
        this->Store.push_back(tmp);
        return tmp;
    }

    T* Insert(T* Doc){
        this->Store.push_back(Doc->id);
        return Doc;
    }

    vector<T*> Insert(vector<T*> Docs){
        this->Store.insert(this->Store.end(), Docs.begin(), Docs.end());
        return Docs;
    }

    void Init(){
        typename list<T*>::iterator It = this->Store.begin();
        for (;It != this->Store.end(); ++It){
            (*It)->Init();
        }
    }

    void Delete(T* Doc){
        if(Doc)
            this->Store.remove(Doc);
        delete Doc;
    }

    T* Remove(T* Doc){
        T* n = new T(*Doc);
        this->Store.remove(Doc);
        delete Doc;
        return n;
    }

    int Index(T* Doc){
        typename list<T*>::iterator It = this->Store.begin();
        for (int i = 0;It != this->Store.end(); ++It){
            ++i;
            if(*It == Doc) return i;
        }
        return -1;
    }

    T* Get(long pl){
        if(pl == -1) return NULL;
        else if(pl == 0) return *this->Store.begin();
        typename list<T*>::iterator It = this->Store.begin();
        while(--pl) ++It;
        return *It;
    }

};

template <typename T>
ostream& operator<<(ostream& stream, Collection<T>& d)
{
    typename list<T*>::iterator It = d.Store.begin();
    stream << '#' << d.Count() << '|' << endl;
    for (;It != d.Store.end(); ++It)
        stream << '\t' << (*It);
    return stream;
}

template <typename T>
istream& operator>>(istream& stream, Collection<T>& d)
{
    char m1(' ');
    int size;
    char mark(' ');
    stream >> m1 >> size >> mark;
    if (!stream || mark != '|' || m1 != '#')
    {    
        stream.setstate(ios::badbit);
        return stream;
    }
    for(int i = 0;i<size;i++){
        T* u = new T();
        stream >> u;
        d.Insert(u);
    }
    return stream;
}

