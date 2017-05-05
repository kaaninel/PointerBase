#pragma once
#include "../include.h"

#define _cre(x) void _Create##x(){ DB.x##s.Create(); }
#define _rea(x) x* _Read##x(function<bool (x*)> q){ return DB.x##s.FindOne(q); }
#define _del(x) void _Delete##x(function<bool (x*)> q){ DB.x##s.Delete(DB.x##s.FindOne(q)); }
#define _upd(x) void _Update##x(function<bool (x*)> q){ DB.x##s.FindOne(q)->Update(); }

#define _CRUD(x) _cre(x); _rea(x); _del(x); _upd(x);

int ColSelect(){
  return s.Select("Tablo",{
    "Kullanici",
    "Konu",
    "Gonderi",
    "Etiket",
    "Begenme"
  });
}

_CRUD(User)
_CRUD(Topic)
_CRUD(Post)
_CRUD(Tag)
_CRUD(Like)

void Create(){
  switch(ColSelect()){
    Rd(1, _CreateUser)
    Rd(2, _CreateTopic)
    Rd(3, _CreatePost)
    Rd(4, _CreateTag)
    Rd(5, _CreateLike)
  }
}

#define _rx(x,y) case x: y##s(); break;

void Read(){
  switch(ColSelect()){
    _rx(1, User)
    _rx(2, Topic)
    _rx(3, Post)
    _rx(4, Tag)
    _rx(5, Like)
  }
}

void GodMode(){
  cout << "\tCRUD Menu" << endl;
  int crudp = s.Select("Islem", {
    "Olustur", "Oku", "Guncelle", "Sil" 
  });

  switch(crudp){
    Rd(1, Create)
    Rd(2, Read)
    //Rd(3, Update)
    //Rd(4, Delete)
  }
}