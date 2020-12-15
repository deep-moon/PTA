#include <iostream>
using namespace std;

int main(){
    int n,m;
    cin>> n >> m;
    int total[n];
    //  初始化
    for(int i = 0; i < n; i++){
        total[i] = 0;
    }
    for(int i = 0; i < m; i++){
        for(int j =0; j < n; j++){
            int num;
            cin>> num;
            total[j] += num;
        }
    }
    int max = 0;
    for(int i = 0; i < n; i++){
        if(total[i] > max){
            max = total[i];
        }
    }
    cout<< max << endl;
    int flag = true;
    for(int i = 0; i < n; i++){
        if(total[i] == max){
            if(flag){
                cout << i + 1;
                flag = false;
            }else{
                cout<< ' ' << i + 1;
            }
        }
    }
    system("pause");
    return 0;
}