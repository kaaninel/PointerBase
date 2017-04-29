#include "include.h"

int main(){
    ifstream ifs("test.pbsf");
    ifs >> DB;
    ifs.close();
    
    //ExampleData();
    while(Running) s.ChangePage(Home);
    
    ofstream ofsf("test.pbsf");
    ofsf << DB;
    ofsf.close();
    cout << endl << endl;
    return 0;
}
