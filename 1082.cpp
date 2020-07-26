#include <iostream>
#include <string>
using namespace std;

int main()
{
    int num;
    scanf("%d",&num);
    int index[num];
    int min = 20005, minIndex = 0, max = 0, maxIndex = 0;
    for(int i = 0; i < num; i++){
        int x,y;
        scanf("%4d %d %d",&index[i],&x,&y);
        int distance = x*x + y*y;
        if(distance > max){
            max = distance;
            maxIndex = i;
        }
        if(distance < min){
            min = distance;
            minIndex = i;
        }
    }
    printf("%04d %04d", index[minIndex], index[maxIndex]);
    system("pause");
    return 0;
}