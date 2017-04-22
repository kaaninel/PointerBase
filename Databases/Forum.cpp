#pragma once
#include "../include.h"


class ForumDB{
public:
    Collection<User> Users;
    Collection<Topic> Topics;
    Collection<Post> Posts;
    Collection<Tag> Tags;
    Collection<Like> Likes;
    ForumDB(){}
    void Drop(){
        Users.Store.clear();
        Topics.Store.clear();
        Posts.Store.clear();
        Tags.Store.clear();
        Likes.Store.clear();
    }
};

ostream& operator<<(ostream& stream, ForumDB& d)
{
    stream  << d.Users
            << d.Topics
            << d.Posts
            << d.Tags
            << d.Likes << endl;
    return stream;
}

istream& operator>>(istream& stream, ForumDB& d)
{
    stream  >> d.Users
            >> d.Topics
            >> d.Posts
            >> d.Tags
            >> d.Likes;
    string line;
    getline(stream, line);
    if (!line.empty()) stream.setstate(ios::badbit);
    d.Users.Init();
    d.Topics.Init();
    d.Posts.Init();
    d.Tags.Init();
    return stream;
}

