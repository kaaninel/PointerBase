#pragma once
#include "../include.h"
#include "Tag.cpp"

class Topic{
public: 
    Topic* id;
    string title;
    time_t created_at;
    time_t uploaded_at;
    User* author;
    Set<Tag> tags;
    Set<Post> posts;
    Topic(string t, User* a){
        id = this;
        created_at = time(0);
        uploaded_at = time(0);
        title = t;
        author = a;
        author->topics.Relate(this);
    }
    ~Topic(){
        cout << "Deleting Topic " << title << endl;
        /*author->topics.UnRelate(this); 
        vector<Tag*> ts = tags.FindVector(_(Tag, true));
        for(auto t: ts) tags.UnRelate(t);
        posts.Loop(_(Post, true), [](Post* x){DB.Posts.Delete(x);});*/
    }
    
    void AddTag(Tag* t){
        tags.Relate(t);
        t->topics.Relate(id);
    }
};