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
    int authorinit;
    Set<Tag> tags = NULL;
    Set<Post> posts = NULL;
    Topic(){
        id = this;
        tags = Set<Tag>(&DB.Tags);
        posts = Set<Post>(&DB.Posts);
    }
    void Update(){
        title =  s.Ask<string>("Başlık");
    }
    void Init(){
        author = DB.Users.Get(authorinit);
        tags.Init();
        posts.Init();
    }
    Topic(string t, User* a){
        id = this;
        created_at = time(0);
        uploaded_at = time(0);
        title = t;
        author = a;
        author->topics.Relate(this);
        tags = Set<Tag>(&DB.Tags);
        posts = Set<Post>(&DB.Posts);
    }
    ~Topic(){
        author->topics.UnRelate(this);
        tags.ForEach([this](Tag* t){ t->topics.UnRelate(this); });
        posts.ForEachI([](Post* t){ DB.Posts.Delete(t); });
    }
    void AddTag(Tag* t){
        tags.Relate(t);
        t->topics.Relate(id);
    }
};

ostream& operator<<(ostream& stream, Topic* const& d)
{
    return stream << StringSerializer(d->title) << " "
                    << d->created_at << " "
                    << d->uploaded_at << " "
                    << DB.Users.Index(d->author)
                    << d->tags
                    << d->posts << "\n";
}

istream& operator>>(istream& stream, Topic*& d)
{
    stream  >> StringSerializer(d->title) 
            >> d->created_at
            >> d->uploaded_at
            >> d->authorinit
            >> d->tags
            >> d->posts;
    return stream;
}