#include <iostream>
#include <fstream>
#include <string>
#include "functionsForADW.h"

using namespace std;

int main() {
	string stroka = readingFile();
	//cout << stroka << endl;
	int size = countDlina(stroka);
	char* perest = new char[size];
	fillMas(stroka, perest);
	cout << "nach perestanovka: ";
	for (int i{ 0 }; i < size; ++i) {
		cout << perest[i] << " ";
	}
	cout << endl;
	string allPerest{ "" };
	allPerest = generateAllPerest(perest, size);
	cout << allPerest;
	writingFile(allPerest);
}