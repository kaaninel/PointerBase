#pragma once
#include "../include.h"

void Profile(User* user){
  cout << endl;
  cout << "\t" << "Kullanici Adi: " << user->username << endl;
  cout << "\t" << "E-mail: " << user->email << endl;
  cout << endl << "Konularim" << endl;
  user->topics.Loop(_(Topic, true),[](Topic* t){ 
    cout << " -> " << t->title << endl;
  });
  cout << endl;

  int p = s.Select("Islem", {
    "Profili duzenle",
    "Geri Dön"
  });

  switch(p){
    case 0: 
      user->Update();
      s.ChangePage(Profile, user);
      break;
  }
}

void Profile(){
  Profile(CurrentUser);
}