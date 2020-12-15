#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <map>

typedef struct{
    string id;
    int score;
} student;
typedef struct{
    int id;
    int people;
} examRoom;

int examRoomTotalPeople[1000];
int examRoomTotalScore[1000];
int main(){
    int n,m;
    vector<student> vectorStudentA;
    vector<student> vectorStudentB;
    vector<student> vectorStudentC;
    map<char, vector<student>> levleStudent;
    map<string, int [1000]> dateExamRoom;
    levleStudent['A'] = vectorStudentA;
    levleStudent['B'] = vectorStudentB;
    levleStudent['C'] = vectorStudentC;
    cin>> n >> m;
    for(int i = 0; i < n; i++){
       string id;
       int score;
       cin>> id >> score;

       // 指令1的一些预操作
       student tmp;
       tmp.id = id;
       tmp.score = score;
       char level = id[0];
       if(levleStudent[level].size() == 0){
           levleStudent[level].push_back(tmp);
       }else{
           if(tmp.score >= levleStudent[level].back().score ){
               levleStudent[level].insert(--levleStudent[level].end(), tmp);
           }else{
               levleStudent[level].push_back(tmp);
           }
       }
       // 指令2的一些预操作
       int examRoomId = stoi(id.substr(1,3));
       examRoomTotalScore[examRoomId] += score;
       examRoomTotalPeople[examRoomId] += 1;

       // 指令3的一些预操作
       string date = id.substr(4,6);
       dateExamRoom[date][examRoomId]++;
    }
    for(int i = 1; i <= m; i++){
       int type;
       cin>> type;
       // 指令1，按分数非升序输出某个指定级别的考生的成绩
       if(type == 1){
           char level;
           cin>> level;
           cout<< "Case " << i << ": " << type << " " << level << endl;
           if(levleStudent[level].size() == 0){
               cout<< "NA" <<endl;
           }else{
               for(int k = 0; k < levleStudent[level].size(); k++){
                   cout<< levleStudent[level][k].id << " " <<  levleStudent[level][k].score << endl;
               }
           }
       }  
       // 指令2，指定考场的考生人数和总分统计输出    
       if(type == 2){
           int examRoomId;
           cin>> examRoomId;
           cout<< "Case " << i << ": " << type << " " << examRoomId << endl;
           if(examRoomTotalPeople[examRoomId] == 0){
               cout<< "NA" <<endl;
           }else{
               cout<< examRoomTotalPeople[examRoomId]<< ' '<< examRoomTotalScore[examRoomId];
           }
       }
       // 指令3，指定日期的考生人数分考场统计输出    
       if(type == 3){
           string date;
           cin>> date;
           cout<< "Case " << i << ": " << type << " " << date << endl;
           if(dateExamRoom.count(date) == 0){
               cout<< "NA" <<endl;
           }else{
               vector<examRoom> vectorExamRoom;
               for(int dIndex = 0; dIndex < 1000 ; dIndex++){
                   if(dateExamRoom[date][dIndex] != 0){
                       examRoom tmp;
                       tmp.id = dIndex;
                       tmp.people = dateExamRoom[date][dIndex];
                       if(vectorExamRoom.size() == 0){
                           vectorExamRoom.push_back(tmp);
                       }else{
                            if(tmp.people >= vectorExamRoom.back().people ){
                                vectorExamRoom.insert(--vectorExamRoom.end(), tmp);
                            }else if(tmp.people == vectorExamRoom.back().people){
                                if(tmp.id < vectorExamRoom.back().id ){
                                    vectorExamRoom.insert(--vectorExamRoom.end(), tmp);
                                }else{
                                    vectorExamRoom.push_back(tmp);
                                }
                            }else{
                                vectorExamRoom.push_back(tmp);
                            }
                       }
                   }
               }
               for(int v = 0; v < vectorExamRoom.size(); v++ ){
                   cout<< vectorExamRoom[v].id << " " << vectorExamRoom[v].people << endl;
               }
           }
       }
    }
    system("pause");
    return 0;
}
