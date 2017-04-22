#pragma once
#include "../include.h"

void Profile(){
  cout << endl;
  cout << "\t" << "Kullanici Adi: " << CurrentUser->username << endl;
  cout << "\t" << "E-mail: " << CurrentUser->email << endl;
  
  CurrentUser->topics.Loop(_(Topic, true),[](Topic* t){ 
    cout << t->title << endl;
    t->posts.Loop(_(Post,true), [](Post* p){ cout << "\t" << p->text << endl; }); 
  });
  cout << endl;

  int p = s.Select("Islem", {
    "Profili duzenle",
    "Yeni Konu",
    "Yeni Gonderi"
  });

  switch(p){
    case 0: 
      CurrentUser->Update();
      break;
  }
}