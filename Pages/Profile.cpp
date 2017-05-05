#pragma once
#include "../include.h"

void Info(User* user){
  cout << endl;
  cout << "\t" << "Kullanici Adi: " << user->username << endl;
  cout << "\t" << "E-mail: " << user->email << endl;
  cout << endl << "Konularim" << endl;
  user->topics.Loop(_(Topic, true),[](Topic* t){ 
    cout << " -> " << t->title << endl;
  });
  cout << endl;

}

void Profile(User* user){
  Info(user);
  int p = s.Select("Islem", {
    "Konular",
    "Geri Dön"
  });

  switch(p){
    Rdx(1, Topics, user)
  }
}

void Profile(){
  Info(CurrentUser);
  int p = s.Select("Islem", {
    "Konular",
    "Profili duzenle",
    "Geri Dön"
  });

  switch(p){
    Rdx(1, Topics, CurrentUser)
    case 2: 
      CurrentUser->Update();
      s.ChangePage(Profile, CurrentUser);
      break;
  }
}