#pragma once
#include "../include.h"

string TopicName(Topic* x){
  return string(x->title).append("\tYazar: ").append(x->author->username);
}

void ReadTopic(){
  int a = s.Select("Konu", DB.Topics.MapSelection(TopicName));
  s.ChangePage(Posts, DB.Topics[a]);
}

void ReadTopic(User* user){
  int a = s.Select("Konu",  user->topics.MapSelection(TopicName));
  s.ChangePage(Posts, user->topics[a]);
}

void EditTopic(){
  int a = s.Select("Konu", DB.Topics.MapSelection(TopicName));
  DB.Topics[a]->Update();
}
void EditTopic(User* user){
  int a = s.Select("Konu",  user->topics.MapSelection(TopicName));
  user->topics[a]->Update();
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

void Topics(User* user){
  s.ChangePage(ReadTopic, user);
}