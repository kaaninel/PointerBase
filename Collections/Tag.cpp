#pragma once
#include "../include.h"

class Tag{
public:
    Tag* id;
    string name;
    Set<Topic> topics;
    Tag(string n){
        id = this;
        name = n;
    }
    ~Tag(){
        cout << "Deleting Tag " << name << endl;
        vector<Topic*> ts = topics.FindVector(_(Topic, true));
        for(auto t: ts) topics.UnRelate(t);
    }
};