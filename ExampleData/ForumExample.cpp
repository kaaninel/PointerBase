
void ExampleData(){

    DB.Drop();
    
    User* Anonymous = DB.Users.Insert(new User("anonymous","1234","anon@k.com"));
    User* Ugur = DB.Users.Insert(new User("ugur","1234","u@k.com"));
    User* Kaan = DB.Users.Insert(new User("kaaninel","1234","k@k.com"));

    Tag* TestTag = DB.Tags.Insert(new Tag("Test"));
    Tag* Language = DB.Tags.Insert(new Tag("Language"));
    Tag* Programming = DB.Tags.Insert(new Tag("Programming"));

    Topic* CPP = DB.Topics.Insert(new Topic("CPP", Kaan));
    Topic* Computer = DB.Topics.Insert(new Topic("Computer", Kaan));
    Topic* Javascript = DB.Topics.Insert(new Topic("Javascript", Kaan));
    Topic* VisualStudio = DB.Topics.Insert(new Topic("VisualStudio", Kaan));

    CPP->AddTag(Language);
    CPP->AddTag(Programming);
    Javascript->AddTag(Language);
    Javascript->AddTag(Programming);
    VisualStudio->AddTag(Programming);
    Computer->AddTag(TestTag);

    //CPP->tags.UnRelate(Language); 

    vector<Post*> Posts = DB.Posts.Insert((vector<Post*>){
        new Post("Test", Kaan, Javascript),
        new Post("Test2", Ugur, VisualStudio)
    });

}