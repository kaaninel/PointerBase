#pragma once
#include "../include.h"

bool Running = true;

void Home(){
  if(!CurrentUser) s.ChangePage(Login);
  s.Clear();
  cout << endl << "\tHosgeldin " << CurrentUser->username << endl;

  int Page = s.Select("Sayfa", {
    "Profilim",
    "Kullanicilar",
    "Konular",
    "Etiketler",
    "GodMode",
    "Cikis Yap"
  });

  switch(Page){
    Rd(1,Profile)
    Rd(2,Users)
    Rd(3,Topics)
    Rd(4,Tags)
    Rd(5,GodMode)
    case 6:
      Running = false;
      break;
  }
}