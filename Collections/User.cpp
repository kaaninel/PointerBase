#pragma once
#include "../include.h"

class User{
public:
    User* id;
    string username;
    string password;
    string email;
    Set<Topic> topics = NULL;
    Set<Post> posts = NULL;
    Set<Like> likes = NULL;
    User(){
        id = this;
        topics = Set<Topic>(&DB.Topics);
        posts = Set<Post>(&DB.Posts);
        likes = Set<Like>(&DB.Likes);
    }
    User(string un, string pw, string em){
        id = this;
        username = un;
        password = pw;
        email = em;
        topics = Set<Topic>(&DB.Topics);
        posts = Set<Post>(&DB.Posts);
        likes = Set<Like>(&DB.Likes);
    }

    void Update(){
        username = s.Ask<string>("Kullanıcı Adı");
        password = s.Ask<string>("Şifre");
        email = s.Ask<string>("E-mail");
    }

    void Init(){
        topics.Init();
        posts.Init();
        likes.Init();
    }

    ~User(){
        //topics.Loop(_(Topic, true), [](Topic* x){DB.Topics.Delete(x);});
        //posts.Loop(_(Post, true), [](Post* x){DB.Posts.Delete(x);});
        cout << username << " deleted!" << endl;
    }

};

ostream& operator<<(ostream& stream, User* const& d)
{
    return stream   << StringSerializer(d->username) << " "
                    << StringSerializer(d->password) << " "
                    << StringSerializer(d->email)
                    << d->topics
                    << d->posts 
                    << d->likes << "\n";
}

istream& operator>>(istream& stream, User*& d)
{
    stream  >> StringSerializer(d->username) 
            >> StringSerializer(d->password)
            >> StringSerializer(d->email)
            >> d->topics
            >> d->posts
            >> d->likes;
    return stream;
}
