#pragma once
#include "../include.h"

Post* SelectPost(Topic* t){
  if(!t->posts.Count()) return NULL;
  int q = s.Select("Gonderi", 
    t->posts.MapSelection(_(Post, x->text)));
  return t->posts[q];
}

void PostList(Topic* t){
  Post* p = SelectPost(t);
  if(!p) {
    cout << "Gonderi Yok" << endl;
    s.Wait();
    return;
  };
  s.Clear();
  cout << endl << 
    endl << "Yazar: " << p->author->username <<
    endl << "Konu:" << p->topic->title <<
    endl << endl << "\t" << p->text << endl;
  s.Wait();
}

void PostCreate(Topic* t){
  DB.Posts.Insert(new Post(s.Ask<string>("Icerik"), CurrentUser, t));
}

void PostEdit(Topic* t){
  Post* p = SelectPost(t);
  if(!p) {
    cout << "Gonderi Yok" << endl;
    s.Wait();
    return;
  };
  s.Clear();
  cout << endl << 
    endl << "Yazar: " << p->author->username <<
    endl << "Konu:" << p->topic->title <<
    endl << endl << "\t" << p->text << endl;
    
  s.Wait();
}

void PostDelete(Topic* t){
  cout << endl << endl << SelectPost(t) << endl;
  s.Wait();
}

void Posts(Topic* t){
  cout << endl << "\t" << t->title << endl << endl;
  int q = s.Select("Islem", {
    "Oku", "Yeni", "Duzenle", "Sil"
  });
  cout << q;
  switch(q){
    Rdx(1, PostList, t)
    Rdx(2, PostCreate, t)
    Rdx(3, PostEdit, t)
    Rdx(4, PostDelete, t)
  }

}

void Posts(){
  Post* p = DB.Posts[s.Select("Gonderi", 
    DB.Posts.MapSelection(_(Post, x->text)))];
  if(!p) {
    cout << "Gonderi Yok" << endl;
    s.Wait();
    return;
  };
  s.Clear();
  cout << endl << 
    endl << "Yazar: " << p->author->username <<
    endl << "Konu:" << p->topic->title <<
    endl << endl << "\t" << p->text << endl;
  s.Wait();

}