#include <iostream>
#include <fstream>
#include <string>
#include "functionsForADN.h"

using namespace std;

int main() {
	string stroka = readingFile();
	//cout << stroka << endl;
	int size = countDlina(stroka);
	int* perest = new int[size] {0}, *invers = new int[size] {0};
	fillMas(stroka, perest);
	cout << "nach perestanovka: ";
	for (int i{0}; i < size; ++i) {
		cout << perest[i] << " ";
	}
	cout << endl;
	string allPerest{ "" };
	allPerest = generateAllPerest(perest, size);
	cout << allPerest;
	writingFile(allPerest);
}