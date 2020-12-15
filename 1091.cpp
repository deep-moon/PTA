#include<iostream>
using namespace std;

void check(int num){
    int flag = false;
    for(int i = 1; i < 10; i++){
        int result =
         i * (num * num);
        if(result % 10 == num || result % 100 == num || result % 1000 == num){
            flag = true;
            cout<< i << " " << result << endl;
            break;
        }
    }
    if(!flag){
        cout<< "No" << endl;
    }
}
int main(){
    int m;
    cin>> m;
    for(int i = 0; i < m; i++){
        int num;
        cin>> num;
        check(num);
    }
    system("pause");
    return 0;
}