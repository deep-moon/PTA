#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

struct examInfo
{
    string schoolName;
    int totalScore = 0;
    int totalPeople = 0;
};

int cmp(examInfo a ,examInfo b)
{
    if(a.totalScore != b.totalScore){
        return a.totalScore > b.totalScore;
    }else{
        if(a.totalPeople != b.totalPeople){
            return a.totalPeople < b.totalPeople;
        }
        else{
            return a.schoolName.compare(b.schoolName);
        }
    }
}

int main()
{
    int n;
    cin>>n;
    getchar();
    map<string,int> schoolToIndex;
    examInfo exam[n+5];
    int count = 0;
    for(int i = 0; i < n; i++){
        string examNum,tmpSchoolName;
        int score;
        cin>>examNum>>score>>tmpSchoolName;
        if(examNum[0] == 'B'){
            score = int(score / 1.5);
        }else if(examNum[0] == 'T'){
            score = int(score * 1.5);
        }
        // 转为小写字母
        transform(tmpSchoolName.begin(), tmpSchoolName.end(),tmpSchoolName.begin(),::tolower);
        // 判断是否有tmpSchoolName
        if(schoolToIndex.count(tmpSchoolName) == 0){
            schoolToIndex[tmpSchoolName] = count;
            exam[count].schoolName = tmpSchoolName;
            exam[count].totalScore += score;
            exam[count].totalPeople++;
            count++;
        }else{
            int schoolIndex = schoolToIndex[tmpSchoolName];
            exam[schoolIndex].totalScore += score;
            exam[schoolIndex].totalPeople++;
        }
        getchar();
    }
    sort(exam,exam + count,cmp);
    // printf("%d",1);
    cout<<count<<endl;
    int sameIndex = 1;
    for(int i = 0;i < count;i++){
        if(i > 0){
            if(exam[i].totalScore == exam[i - 1].totalScore){
                cout<<sameIndex<<" ";
            }else{
                cout<<i+1<<" ";
                sameIndex = i + 1;
            }
        }else{
            cout<<1<<" ";
        }
        cout<<exam[i].schoolName<<" "<<exam[i].totalScore<<" "<<exam[i].totalPeople<<endl;
    }
    system("pause");
    return 0;
}