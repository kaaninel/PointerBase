#pragma once
#include "../include.h"

class User{
public:
    User* id;
    string username;
    string password;
    string email;
    Set<Topic> topics;
    Set<Post> posts;
    User(string un, string pw, string em){
        id = this;
        username = un;
        password = pw;
        email = em;
    }
    ~User(){
        //topics.Loop(_(Topic, true), [](Topic* x){DB.Topics.Delete(x);});
        //posts.Loop(_(Post, true), [](Post* x){DB.Posts.Delete(x);});
        cout << username << " deleted!" << endl;
    }

};