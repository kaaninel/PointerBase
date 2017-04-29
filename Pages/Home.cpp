#pragma once
#include "../include.h"

bool Running = true;

#define Rd(n,P) case n: s.ChangePage(P); break;

void Home(){
  if(!CurrentUser) s.ChangePage(Login);
  s.Clear();
  cout << endl << "\tHosgeldin " << CurrentUser->username << endl;

  int Page = s.Select("Sayfa", {
    "Profilim",
    "Kullanicilar",
    "Etiketler",
    "Konular",
    "Cikis Yap"
  });

  switch(Page){
    Rd(1,Profile)
    Rd(2,Users)
    Rd(3,Topics)
    Rd(4,Tags)
    case 5:
      Running = false;
      break;
  }
}