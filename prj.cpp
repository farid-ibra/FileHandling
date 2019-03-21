#include <iostream>
#include <stdlib.h>
#include <string>                       ///Library declaration sector
#include <vector>
#include "prj.h"
#include <fstream>
using namespace std;
///****************************************************************************************************
void readFile(string InputFile, vector <employee> &W){ ///reads file from input.txt
employee worker;
int pos; ///position
string tmp1,tmp2;
ifstream f1(InputFile.c_str(),ifstream::in);
if(f1.is_open()){
    while(!f1.eof()){
        getline(f1,tmp1);
        if(tmp1!=""){
            pos=tmp1.find(";"); ///finds first ;
            tmp2=tmp1.substr(0,pos);
            worker.name=tmp2;
            tmp1=tmp1.substr(pos+1);
            pos=tmp1.find(";"); ///finds second ;
            tmp2=tmp1.substr(0,pos);
            worker.age=atoi(tmp2.c_str());
            tmp1=tmp1.substr(pos+1);
            pos=tmp1.find(";");
            pos=tmp1.find(";"); ///finds third ;
            tmp2=tmp1.substr(0,pos);
            worker.post=tmp2;
            tmp1=tmp1.substr(pos+1);
            worker.salary=atoi(tmp1.c_str());
            W.push_back(worker);

        }
    }
}
else{cerr<<"Error to open file."<<endl;}
}
///****************************************************************************************************
int YoungestEmployee(vector <employee> W){ ///Task A
int ind=200; ///temporary variable for deciding youngest employee.No one's age is more than 200 in input.txt file
int i;
for(i=0;i<W.size();i++){
    if(W.at(i).age<ind){
        ind=W.at(i).age;
    }
}
return ind;
}
///****************************************************************************************************
int maInName(vector <employee> W){ ///Task B
int cnt=0; ///counter for founding names with "ma"
int i,cnt1=-1,cnt2=-1,cnt3=-1,cnt4=-1;
for(i=0;i<W.size();i++){
cnt1=W.at(i).name.find("ma");
cnt2=W.at(i).name.find("Ma");
cnt3=W.at(i).name.find("mA");
cnt4=W.at(i).name.find("MA");
    if(cnt1>-1 || cnt2>-1 || cnt3>-1 || cnt4>-1){
        cnt++;
    }
}
return cnt;
}
///****************************************************************************************************
int threeMoreName(vector <employee> W, vector <string> &Vector ){///Task C
int counter=0;
int i,cnt=0;
string tmp;
for(i=0;i<W.size();i++){
    int pos,dos,cnt=0;
    pos=W.at(i).name.find(" ");
    if(pos>0){
        cnt++;
        tmp=W.at(i).name.substr(pos+1);
        dos=tmp.find(" ");
        if(dos>0) {cnt++;}
    }
    if(cnt>1){counter++; Vector.push_back(W.at(i).name);}
}
return counter;
}
///****************************************************************************************************
void WriteToFile(string &OutputFile, int A, int B, int C, vector <string> Vector){///Print to output.txt
ofstream f1(OutputFile.c_str());
if(f1.is_open()){
    f1<<"Index of youngest employee: "<<A<<endl;
    f1<<"Number of employees have 'ma' in their name: "<<B<<endl;
    f1<<"Number of employees whose name consist of three or more words: "<<C<<endl;
    f1<<"And their names: ";
    for(int i=0;i<Vector.size();i++){
        f1<<Vector[i]<<" , ";
    }
}
else{cerr<<"error opening output file"<<endl;}
f1.close();
}
