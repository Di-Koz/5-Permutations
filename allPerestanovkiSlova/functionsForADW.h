#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#ifndef FUNCTIONSFORADN_H
#define FUNCTIONSFORADN_H

string readingFile();
int countDlina(string str);
void fillMas(string str, char* arr);
bool isNextPerest(char* arr, int dlina);
int findIndMinOfBigger(int indL, int R, char* arr, int dlina);
void invert(char* arr, int indR, int dlina);
string createNewPerest(char* perest, int dlina);
string generateAllPerest(char* perest, int dlina);
void writingFile(string str);

#endif