#pragma once
#include "../include.h"

vector<string> TopicList(){
  return DB.Topics.MapSelection(_(Topic, 
    string(x->title).append("\tYazar: ").append(x->author->username)));
}

void ReadTopic(){
  int a = s.Select("Konu", TopicList());
  s.ChangePage(Posts, a);
}

void EditTopic(){
  int a = s.Select("Konu", TopicList());
  DB.Topics.Get(a)->Update();
}

void Topics(){
  int a = s.Select("Islem", {
    "Oku",
    "Yeni",
    "Duzenle"
  });

  switch(a){
    case 1: s.ChangePage(ReadTopic); break;
    case 2: DB.Topics.Create(); break;
    case 3: s.ChangePage(EditTopic); break;
  }


}