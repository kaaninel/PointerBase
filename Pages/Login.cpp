#pragma once
#include "../include.h"

User* CurrentUser = NULL;

void Login(){
  int p = s.Select("Islem", {
    "Giris Yap",
    "Kayit Ol"
  });
  int tryc = 0;
  s.Clear();
  if(p == 2) DB.Users.Create();
  while(!CurrentUser && tryc < 3){
    s.Clear();
    if(tryc) cout << "Tekrar Deneyin!" << endl;
    string un = s.Ask<string>("Kullanici Adi");
    string pw = s.Ask<string>("Sifre");
    CurrentUser = DB.Users.FindOne([&](User* u){return u->username == un && u->password == pw;});
    tryc++;
  }
  if(tryc > 2) cout << "Çok fazla yanlış deneme!" << endl;
}