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
        post->likes.UnRelate(this);
        user->likes.UnRelate(this);
    }
    void Update(){
        user = DB.Users.FindOODR<string>("Kullanıcı Adı",[](User* u, string s){return u->username == s;});
        post =  DB.Posts.FindOODR<string>("Gonderi",[](Post* u, string s){return u->text == s;});
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
