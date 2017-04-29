#pragma once
#include "../include.h"

template <typename T>
class Collection;

template <typename T>
class Set{
public:
    list<int> InitIds;
    Collection<T>* CStore = NULL;
    list<T*> Store;
    Set(){}
    Set(Collection<T>* Cl){
        CStore = Cl;
    }
    ~Set(){}

    void Relate(T* id){
        Store.push_back(id);
    }

    void UnRelate(T* id){
        Store.remove(id);
    }

    void Init(){
        if(!CStore && InitIds.size() == 0) return;
        list<int>::iterator It = InitIds.begin();
        for (;It != InitIds.end(); ++It){
            Store.push_back(CStore->Get(*It));
        }
    }

    T* FindOne(function<bool (T*)> cmp){
        typename list<T*>::iterator It = Store.begin();
        for (;It != Store.end(); ++It)
            if(cmp(*It)) return *It;
        return NULL;
    }
    
    T* FindOneOrDefault(function<bool (T*)> cmp){
        typename list<T*>::iterator It = Store.begin();
        for (;It != Store.end(); ++It)
            if(cmp(*It)) return *It;
        return *Store.begin();
    }

    template <typename t>
    T* FindOODR(string q, function<bool (T*, t)> cmp){
        typename list<T*>::iterator It = Store.begin();
        t tmp = s.Ask<t>(q);
        for (;It != Store.end(); ++It)
            if(cmp(*It, tmp)) return *It;
        return *Store.begin();
    }

    list<T*> Find(function<bool (T*)> cmp){
        typename list<T*>::iterator It = Store.begin();
        list<T*> tmp; 
        for (;It != Store.end(); ++It)
            if(cmp(*It)) tmp.push_back(*It);
        return tmp;
    }

    list<T*> Map(function<bool (T*)> cmp){
        typename list<T*>::iterator It = Store.begin();
        list<T*> tmp; 
        for (;It != Store.end(); ++It)
            tmp.push_back(cmp(*It));
        return tmp;
    }

    vector<string> MapSelection(function<string (T*)> cmp){
        typename list<T*>::iterator It = Store.begin();
        vector<string> tmp; 
        for (;It != Store.end(); ++It)
            tmp.push_back(cmp(*It));
        return tmp;
    }

    vector<string> MapSelection(function<bool (T*)> cmp, function<string (T*)> lt){
        typename list<T*>::iterator It = Store.begin();
        vector<string> tmp; 
        for (;It != Store.end(); ++It)
            if(cmp(*It)) tmp.push_back(lt(*It));
        return tmp;
    }

    vector<T*> FindVector(function<bool (T*)> cmp){
        typename list<T*>::iterator It = Store.begin();
        vector<T*> tmp; 
        for (;It != Store.end(); ++It)
            if(cmp(*It)) tmp.push_back(*It);
        return tmp;
    }

    int Count(function<bool (T*)> cmp){
        typename list<T*>::iterator It = Store.begin();
        int tmp = 0; 
        for (;It != Store.end(); ++It)
            if(cmp(*It)) tmp++;
        return tmp;
    }

    bool Exists(function<bool (T*)> cmp){
        typename list<T*>::iterator It = Store.begin();
        for (;It != Store.end(); ++It)
            if(cmp(*It)) return true;
        return false;
    }

    void Loop(function<bool (T*)> cmp, function<void (T*)> lp){
        typename list<T*>::iterator It = Store.begin();
        for (;It != this->Store.end(); ++It)
            if(cmp(*It)) lp(*It);
    }

    void ForEach(function<void (T*)> lp){
        typename list<T*>::iterator It = Store.begin();
        for (;It != this->Store.end(); ++It)
            lp(*It);
    }

    void ForEachI(function<void (T*)> lp){
        list<T*> t = this->Find(_(T, true));
        typename list<T*>::iterator It = t.begin();
        for (;It != t.end(); ++It)
            lp(*It);
    }

    size_t Count(){
        return Store.size();        
    }

};

template <typename T>
ostream& operator<<(ostream& stream, Set<T>& data)
{
    if(!data.CStore) return stream;
    typename list<T*>::iterator It = data.Store.begin();
    stream << endl << "\t\t#";
    stream << data.Store.size() << "|";
    for (;It != data.Store.end(); ++It)
        stream << data.CStore->Index(*It) << " ";
    return stream;
}

template <typename T>
istream& operator>>(istream& stream, Set<T>& d)
{
    char m1(' ');
    int size;
    char mark(' ');
    stream >> m1 >> size >> mark;
    if (!stream || mark != '|' || m1 != '#')
    {    
        stream.setstate(ios::badbit);
        return stream;
    }
    for(int i = 0;i<size;i++){
        int u = 0;
        stream >> u;
        d.InitIds.push_back(u);
    }
    return stream;
}
