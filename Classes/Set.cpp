#pragma once
#include "../include.h"

template <typename T>
class Set{

public:
    list<T*> Store;
    Set(){}
    ~Set(){
        
    }

    void Relate(T* id){
        Store.push_back(id);
    }

    void UnRelate(T* id){
        Store.remove(id);
    }

    T* FindOne(bool (*cmp)(T*)){
        typename list<T*>::iterator It = Store.begin();
        for (;It != Store.end(); ++It)
            if(cmp(*It)) return *It;
        return NULL;
    }

    list<T*> Find(bool (*cmp)(T*)){
        typename list<T*>::iterator It = Store.begin();
        list<T*> tmp; 
        for (;It != Store.end(); ++It)
            if(cmp(*It)) tmp.push_back(*It);
        return tmp;
    }

    vector<T*> FindVector(bool (*cmp)(T*)){
        typename list<T*>::iterator It = Store.begin();
        vector<T*> tmp; 
        for (;It != Store.end(); ++It)
            if(cmp(*It)) tmp.push_back(*It);
        return tmp;
    }

    int Count(bool (*cmp)(T*)){
        typename list<T*>::iterator It = Store.begin();
        int tmp = 0; 
        for (;It != Store.end(); ++It)
            if(cmp(*It)) tmp++;
        return tmp;
    }

    bool Exists(bool (*cmp)(T*)){
        typename list<T*>::iterator It = Store.begin();
        for (;It != Store.end(); ++It)
            if(cmp(*It)) return true;
        return false;
    }

    void Loop(bool (*cmp)(T*), void (*lp)(T*)){
        typename list<T*>::iterator It = Store.begin();
        for (;It != this->Store.end(); ++It)
            if(cmp(*It)) lp(*It);
    }

};