#pragma once
#include "../include.h"
#include <cstdlib>

class Screen{

public:
  Screen(){}
  template <typename T>
  T Read(){
    T tmp;
    cin >> tmp;
    return tmp;
  }
  
  template <typename T>
  T Ask(string q){
    cout << " " << q << ": ";
    return this->Read<T>();
  }

  void Clear(){
    #if defined(_WIN32) 
      system("cls");
    #else
      system("clear");   
    #endif  
  }

  void ChangePage(void (*page)()){
    this->Clear();
    page();
  }

  template <typename T>
  void ChangePage(void (*page)(T), T b){
    this->Clear();
    page(b);
  }

  int Select(string q,vector<string> options){
    int l = options.size();
    cout << endl << endl;
    for(int i = 0; i < l; i++)
      cout << "\t" << (i+1) << ": " + options[i] << endl;
    cout << endl << endl;
    return Ask<int>(q);
  }

};