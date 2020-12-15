#include <iostream>
#include <string>
using namespace std;

int isPrime(int num){
    if(num == 2){
        return true;
    }
    if(num % 2 == 0){
        return false;
    }
    for(int i = 3;i * i <= num;i += 2){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}
int main(){
    int l,k;
    cin>> l >> k;
    cin.get();
    string num;
    getline(cin,num);
    int flag = true;
    for(int i = 0; i <= l - k;i++){
        string subStr = num.substr(i,k);
        int subNum = stoi(subStr);
        if(isPrime(subNum)){
            cout<< subStr <<endl;
            flag = false;
            break;
        }
    }
    if(flag){
         cout<< 404 <<endl;
    }
    system("pause");
    return 0;
}
