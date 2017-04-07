#pragma once
#include "../include.h"

class Post{
public:
    Post* id;
    string text;
    time_t created_at;
    time_t uploaded_at;
    User* author;
    Topic* topic;

    Post(string t, User* a, Topic* tp){
        id = this;
        created_at = time(0);
        uploaded_at = time(0);
        text = t;
        author = a;
        topic = tp;
        author->posts.Relate(this);
        topic->posts.Relate(this);
    }
    ~Post(){
        cout << "Deleting Post " << text << endl;
        /*author->posts.UnRelate(this);
        topic->posts.UnRelate(this);*/
    }
};