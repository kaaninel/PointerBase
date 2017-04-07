#include "include.h"

int main(){
    ExampleData();
    cout << DB.Posts.FindOne([](Post* p){ return p->text == "Test2";})->author->username << endl;
    return 0;
}