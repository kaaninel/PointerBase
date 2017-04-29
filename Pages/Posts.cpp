#pragma once
#include "../include.h"

void Posts(int topic){
  Topic* t = DB.Topics.Get(topic);
  cout << endl << "\t" << t->title << endl << endl;

  int a = s.Select("Gonderi", DB.Posts.MapSelection(
    [t](Post* x){ return x->topic == t; }, _(Post, x->text)));
}