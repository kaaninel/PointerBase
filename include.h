#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <ctime>
#include <functional>
#include <fstream>
using namespace std;

// Lambda Expression
#define _(Type, func) [](Type* x){ return func; }

#include "Classes/Serialize.cpp"
#include "Classes/Screen.cpp"
Screen s;
#include "Classes/Set.cpp"
#include "Classes/Collection.cpp"

class User;
class Topic;
class Post;
class Tag;
class Like;

#include "Databases/Forum.cpp"

ForumDB DB;

#include "Collections/User.cpp"
#include "Collections/Topic.cpp"
#include "Collections/Post.cpp"
#include "Collections/Tag.cpp"
#include "Collections/Like.cpp"

#include "ExampleData/ForumExample.cpp"

#include "Pages/Login.cpp"
#include "Pages/Posts.cpp"
#include "Pages/Profile.cpp"
#include "Pages/Tags.cpp"
#include "Pages/Topics.cpp"
#include "Pages/Users.cpp"
#include "Pages/Home.cpp"

#include "Examples/Loop.cpp"
#include "Examples/Search.cpp"