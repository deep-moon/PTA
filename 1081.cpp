#include <iostream>
#include <string>
using namespace std;

string passwordVaildator(string password){
    if(password.length() < 6){
        return "Your password is tai duan le.";
    }else{
        bool hasAlpha = false;
        bool hasNumber = false;
        for(int i = 0; i < password.length(); i++){
            if((password[i] >='a' && password[i] <= 'z') ||
             (password[i] >='A' && password[i] <= 'Z') || 
             (password[i] >='0' && password[i] <= '9') ||
             (password[i] == '.')){
                if((password[i] >='0' && password[i] <= '9')){
                    hasNumber = true;
                }else{
                    if(password[i] != '.'){
                        hasAlpha = true;
                    }
                }
             }else{
                 return "Your password is tai luan le.";
             }
        }
        if(hasNumber && hasAlpha){
            return "Your password is wan mei.";
        }else{
            if(!hasAlpha){
                return "Your password needs zi mu.";
            }
            if(!hasNumber){
                return "Your password needs shu zi.";
            }
        }
    }
}

int main()
{
    int num;
    cin>> num;
    getchar();
    for(int i = 0; i < num; i++){
        string passwordInput;
        getline(cin, passwordInput);
        string result = passwordVaildator(passwordInput);
        cout<< result<< endl;
    }
    system("pause");
    return 0;
}