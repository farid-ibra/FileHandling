#include <iostream>
#include <stdlib.h>
#include <string>                       ///Library declaration sector
#include <vector>
#include "prj.h"
using namespace std;
///**************************************************************************************************
int main(){
    string ifname = "input.txt";
    string ofname = "output.txt";
    vector <employee> V;   ///Vector for struct
    vector <string> taskC; /// additional vector for employee's who has more than three word in name
    readFile(ifname,V);    ///reads from file input.txt
    int index = YoungestEmployee(V);    ///function for task A  "Index of Youngest Employee"
    int MA = maInName(V);               ///function for task B  "Count the employee's who has "ma" in their name
    int three = threeMoreName(V,taskC); ///function for task C  "Employees whose name consist more than 3 or more words
    WriteToFile(ofname,index,MA,three,taskC);  ///prints answers to file output.txt
    return 0;
}
