#ifndef PRJ_H_INCLUDED
#define PRJ_H_INCLUDED
#endif // PRJ_H_INCLUDED
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;
///emploee's data
struct employee{
string name;
int age;
string post;
int salary;
};
///Functions
void readFile(string InputFile, vector <employee> &W);                                 ///reads file from input.txt
int YoungestEmployee(vector <employee> W);                                              ///Task A
int maInName(vector <employee> W);                                                      ///Task B
int threeMoreName(vector <employee> W, vector <string> &Vector );                       ///Task C
void WriteToFile(string &OutputFile, int A, int B, int C, vector <string> Vector);      ///Print to output.txt
