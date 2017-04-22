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
    "Konular",
    "Gonderiler",
    "Etiketler",
    "Kullanicilar",
    "Cikis Yap"
  });

  switch(Page){
    Rd(0,Profile)
    Rd(1,Topics)
    Rd(2,Posts)
    Rd(3,Tags)
    Rd(4,Users)
    case 5:
      Running = false;
      break;
  }
}