#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string readingFile() {
	ifstream file("input.txt");
	string str{ "" }, str2{ "" };
	while (!file.eof()) {
		getline(file, str2);
		str += str2 + ' ';
	}
	file.close();
	return str;
}

int countDlina(string str) {
	int lenght = str.size(), word{ 0 };

	for (int i{ 0 }; i < lenght - 1; ++i) {
		if ((str[i] != ' ') && (str[i + 1] == ' ')) {
			++word;
		}
	}
	return word;
}
//заполнение массива, даже с учетом того, что в строке могут быть не
//однозначные числа
void fillMas(string str, char* arr) {
	int lenght = str.size(), ind{ 0 };

	for (int i{ 0 }; i < lenght; ++i) {
		if (str[i] != ' ') {
			arr[ind] = str[i];
			++ind;
		}
	}
}

bool isNextPerest(char* arr, int dlina) {
	for (int i{ dlina - 2 }; i >= 0; --i) {
		if (arr[i] < arr[i + 1]) {
			return true;
		}
	}
	return false;
}
//поиск наименьшего из чисел, которые больше числа
int findIndMinOfBigger(int indL, int indR, char* arr, int dlina) {
	int ch{ arr[indL] }, ch2{ arr[indR] }, indMOB{ indR };
	for (int i{ indR + 1 }; i < dlina; ++i) {
		if ((arr[i] < ch2) && (arr[i] > ch)) {
			ch2 = arr[i];
			indMOB = i;
		}
	}
	//cout << ch2 << endl;
	return indMOB;
}
//инвертация
void invert(char* arr, int indR, int dlina) {
	char* zapasMas = new char[dlina - indR], ind{ 0 };

	for (int i{ dlina - 1 }; i >= indR; --i) {
		zapasMas[ind] = arr[i];
		++ind;
	}
	ind = 0;
	/*for (int i{0}; i < dlina - indR; ++i) {
		cout << zapasMas[i] << " ";
	}
	cout << endl;*/
	for (int i{ indR }; i < dlina; ++i) {
		arr[i] = zapasMas[ind];
		++ind;
	}
}

string createNewPerest(char* perest, int dlina) {
	string newPerest{ "" };
	int indLeft{ 0 }, indRight{ 0 };
	for (int i{ dlina - 2 }; i >= 0; --i) {
		if (perest[i] < perest[i + 1]) {
			indLeft = i;
			indRight = i + 1;
			break;
		}
	}
	int indObmen = findIndMinOfBigger(indLeft, indRight, perest, dlina);
	//cout << indLeft << " " << indRight << " "<< indObmen << endl;
	char c{ perest[indObmen] };
	perest[indObmen] = perest[indLeft];
	perest[indLeft] = c;

	invert(perest, indRight, dlina);
	/*for (int i{ 0 }; i < dlina; ++i) {
		cout << perest[i] << " ";
	}
	cout << endl;*/

	//присваивание массива символов строке и удаление оттуда всего лишнего
	newPerest = (const char*)perest;
	newPerest.erase(dlina, newPerest.size() - dlina);
	//расстановка пробелов
	for (int i{dlina}; i > 0; --i) {
		newPerest.insert(i, 1, ' ');
	}

	return newPerest;
}

string generateAllPerest(char* perest, int dlina) {
	string allPerest{ "" };
	while (isNextPerest(perest, dlina)) {
		string currentPerest = createNewPerest(perest, dlina);
		/*cout << "new: " << currentPerest << endl;*/
		allPerest += currentPerest + '\n';
	}
	return allPerest;
}

void writingFile(string str) {
	ofstream file("output.txt");
	file << str;
	file.close();
}