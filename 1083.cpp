#include <iostream>
#include <string>
using namespace std;

int main()
{
    int num;
    scanf("%d",&num);
    int count[num + 5];
    for(int i = 0; i < num + 5; i++){
      count[i] = 0;
    }
    for(int i = 1; i <= num; i++){
        int front = i,back;
        scanf("%d",&back);
        if(front > back){
            count[front - back]++;
        }else{
            count[back - front]++;
        }
    }
    for(int i = num + 4; i >= 0; i--){
      if(count[i] != 0 && count[i] != 1){
          printf("%d %d\n",i,count[i]);
      }
    }
    system("pause");
    return 0;
}