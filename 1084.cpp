#include <iostream>
#include <string>
using namespace std;

string solve(string d){
    // cout<<d<<endl;
    char last = d[0];
    int count = 0;
    string result = "";
    for(int i = 0;i < d.length(); i++){
        if(d[i] == last){
            count++;
        }else{
            result = result + last + char('0' + count);
            count = 1; 
        }
        last = d[i];
        // 最后一个字符的情况
        if(i == d.length() - 1){
             result = result + last + char('0' + count);
        }
    }
    return result;
}

int main()
{
    string d;
    int n;
    cin>>d>>n;
    string result = d;
    for(int i = 0; i < (n - 1); i++){
        result = solve(result);
    }
    cout<< result;
    system("pause");
    return 0;
}