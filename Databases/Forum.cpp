#pragma once
#include "../include.h"

class ForumDB{
public:
    Collection<User> Users;
    Collection<Topic> Topics;
    Collection<Post> Posts;
    Collection<Tag> Tags;
    ForumDB(){}
    ForumDB(string file){
        ifstream ifs(file, ios::binary);
        ifs.read((char *)this, sizeof(ForumDB));        
    }
    ~ForumDB(){}
    void Save(string file){
	    ofstream ofs(file, ios::binary);
    	ofs.write((char *)this, sizeof(ForumDB));
    }
};