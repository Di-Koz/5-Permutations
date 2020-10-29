#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#ifndef FUNCTIONSFORTI_H
#define FUNCTIONSFORTI_H

string readingFile();
int countDlina(string str);
void fillMas(string str, int* arr);
int findNumInvers(int* arr, int ind);
bool isEmpty(int ind, int* arr);
void sdvigToRight(int* arr, int indNach, int dlina);
int findMax(int* arr, int dlina);
string createPerest(int nachEl, int* tableInvers, int dlina);
void writingFile(string str);

#endif
