#pragma once
#include "../include.h"
#include "Set.cpp"

template <typename T>
class Collection : public Set<T>{
public:
    Collection() : Set<T>(){}
    ~Collection(){}

    T* Insert(T* Doc){
        this->Store.push_back(Doc->id);
        return Doc;
    }

    vector<T*> Insert(vector<T*> Docs){
        this->Store.insert(this->Store.end(), Docs.begin(), Docs.end());
        return Docs;
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

};