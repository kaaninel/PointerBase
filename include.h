#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <ctime>
#include <fstream>
using namespace std;

// Lambda Expression
#define _(Type, func) [](Type* x){ return func; }

#include "Classes/Set.cpp"
#include "Classes/Collection.cpp"

class User;
class Topic;
class Post;
class Tag;

#include "Databases/Forum.cpp"

ForumDB DB;

#include "Collections/User.cpp"
#include "Collections/Topic.cpp"
#include "Collections/Post.cpp"
#include "Collections/Tag.cpp"

#include "ExampleData/ForumExample.cpp"

#include "Examples/Loop.cpp"
#include "Examples/Search.cpp"