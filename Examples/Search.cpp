
void SearchMacro(){
    cout << DB.Posts.FindOne(_(Post,x->text == "Test2"))->text << endl;
}

void SearchLambda(){
    cout << DB.Posts.FindOne([](Post* p){ return p->text == "Test2";})->text << endl;
}
