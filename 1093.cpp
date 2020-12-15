#include <iostream>
#include <string>
using namespace std;

int main(){
    string a,b;
    int flag[150];
    for(int i = 0;i < 150;i++){
        flag[i] = 0;
    }
    getline(cin,a);
    getline(cin,b);
    for(int i = 0;i < a.length(); i++){
        int index = int(a[i]);
        if(!flag[index]){
            flag[a[i]] = 1;
            cout<< a[i];
        }
    }
    for(int i = 0;i < b.length(); i++){
        int index = int(b[i]);
        if(!flag[index]){
            flag[b[i]] = 1;
            cout<< b[i];
        }
    }
    cout<< endl;
    system("pause");
    return 0;
}
