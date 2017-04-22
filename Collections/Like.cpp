#pragma once
#include "../include.h"

class Like{
public: 
    Like* id;
    Post* post;
    User* user;
    long postinit;
    long userinit;
    Like(User* u, Post* p){
        id = this;
        post = p;
        user = u;
    }
    Like(){
        id = this;
    }
    void Init(){
        post = DB.Posts.Get(postinit);
        user = DB.Users.Get(userinit);
    }
    ~Like(){
        
    }
};

ostream& operator<<(ostream& stream, Like* const& d)
{
    return stream << d->post << " " << d->user << endl;
}

istream& operator>>(istream& stream, Like*& d)
{
    stream  >> d->postinit >> d->userinit;
    return stream;
}
