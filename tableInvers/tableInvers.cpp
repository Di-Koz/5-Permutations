#include <iostream>
#include <fstream>
#include <string>
#include "functionsForTI.h"

using namespace std;

int main() {
	string stroka = readingFile();
	//cout << stroka << endl;
	int size = countDlina(stroka);
	int* perest = new int[size] {0}, * invers = new int[size] {0};
	fillMas(stroka, perest);
	cout << "perestanovka:" << endl;
	for (int i{ 0 }; i < size; ++i) {
		cout << perest[i] << " ";
	}
	//создание таблицы инверсий
	for (int i{ 0 }; i < size; ++i) {
		int indInInvers = perest[i] - 1;
		int kolvoInvers = findNumInvers(perest, i);
		invers[indInInvers] = kolvoInvers;
	}
	cout << endl << "tablitsa inversiy:" << endl;
	string inversStroka{ "" };
	for (int i{ 0 }; i < size; ++i) {
		cout << invers[i] << " ";
		inversStroka += to_string(invers[i]) + ' ';
	}	
	cout << endl;
	int maxEl = findMax(perest, size);
	cout << "sozdanie perestanovki po tablitse iversiy:" 
		<< endl << createPerest(maxEl, invers, size);
	writingFile(inversStroka);
}
