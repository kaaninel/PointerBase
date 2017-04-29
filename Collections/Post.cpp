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
  long authorinit;
  long topicinit;
  Set<Like> likes = NULL;

  Post(){
    id = this;
    created_at = time(0);
    likes = Set<Like>(&DB.Likes);
  }

  void Init(){
    author = DB.Users.Get(authorinit);
    topic = DB.Topics.Get(topicinit);
    likes.Init();
  }

  void Update(){
    uploaded_at = time(0);
    if(author) author->posts.UnRelate(this);
    if(topic) topic->posts.UnRelate(this);
    author = DB.Users.FindOODR<string>("Kullanıcı Adı",[](User* u, string s){return u->username == s;});
    topic =  DB.Topics.FindOODR<string>("Konu",[](Topic* u, string s){return u->title == s;});
    text = s.Ask<string>("Yazı");
    author->posts.Relate(this);
    topic->posts.Relate(this);
  }

  Post(string t, User* a, Topic* tp){
    id = this;
    created_at = time(0);
    uploaded_at = time(0);
    text = t;
    author = a;
    topic = tp;
    author->posts.Relate(this);
    topic->posts.Relate(this);
    likes = Set<Like>(&DB.Likes);
  }
  ~Post(){
    author->posts.UnRelate(this);
    topic->posts.UnRelate(this);
    likes.ForEachI([](Like* t){ DB.Likes.Delete(t); });
  }
};

ostream& operator<<(ostream& stream, Post* const& d)
{
    return stream << StringSerializer(d->text) << " "
                    << d->created_at << " "
                    << d->uploaded_at << " " 
                    << DB.Users.Index(d->author) << " " 
                    << DB.Topics.Index(d->topic) << " " 
                    << d->likes << "\n";
}

istream& operator>>(istream& stream, Post*& d)
{
  stream  >> StringSerializer(d->text) 
          >> d->created_at
          >> d->uploaded_at
          >> d->authorinit
          >> d->topicinit
          >> d->likes;
  return stream;
}