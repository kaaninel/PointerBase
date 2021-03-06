#pragma once
#include "../include.h"

class Tag{
public:
    Tag* id;
    string name;
    Set<Topic> topics;
    Tag(){
        id = this;
        topics = Set<Topic>(&DB.Topics);
    }
    void Update(){
        name = s.Ask<string>("Etiket Adı");
    }
    void Init(){
        topics.Init();
    }
    Tag(string n){
        id = this;
        name = n;
        topics = Set<Topic>(&DB.Topics);
    }
    
    void Serialize(ofstream &o){
        o << name << endl;
    }
    ~Tag(){
        //topics.ForEach([this](Topic* t){ t->tags.UnRelate(this); });
    }
};

ostream& operator<<(ostream& stream, Tag* const& d)
{
    return stream << StringSerializer(d->name) << d->topics << "\n";
}

istream& operator>>(istream& stream, Tag*& d)
{
    stream  >> StringSerializer(d->name) >> d->topics;
    return stream;
}