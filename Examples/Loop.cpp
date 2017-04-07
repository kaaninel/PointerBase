
void LoopMacro(){
    DB.Users.FindOne(_(User,x->username == "kaaninel"))->topics.Loop(
        _(Topic, x->tags.Exists(_(Tag, x->name == "Language"))),
        [](Topic* x){cout << x->title << endl;}
    );
}

void LoopLambda(){
    DB.Users.FindOne(
        [](User* u){ return u->username == "kaaninel"; })->topics.Loop(
        [](Topic* t) { return t->tags.Exists(
            [](Tag* tg){return tg->name == "Language";}); }, 
                [](Topic* t){cout << t->title << endl;});
}