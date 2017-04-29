#pragma once
#include "../include.h"

void Users(){
  int usr = s.Select("Kullanıcı", DB.Users.MapSelection(_(User, x->username)));
  s.ChangePage(Profile, DB.Users.Get(usr));
}