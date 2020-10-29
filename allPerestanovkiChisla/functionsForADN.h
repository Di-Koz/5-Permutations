#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#ifndef FUNCTIONSFORADN_H
#define FUNCTIONSFORADN_H

string readingFile();
int countDlina(string str);
void fillMas(string str, int* arr);
bool isNextPerest(int* arr, int dlina);
int findIndMinOfBigger(int indL, int R, int* arr, int dlina);
void invert(int* arr, int indR, int dlina);
string createNewPerest(int* perest, int dlina);
string generateAllPerest(int* perest, int dlina);
void writingFile(string str);

#endif