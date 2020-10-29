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
void fillMas(string str, int* arr) {
	int lenght = str.size(), ind{ 0 };

	for (int i{ 0 }; i < lenght;) {
		int ind2{ i }, step{ 1 }, step2{ 0 };
		string subStr{ "" };
		bool space{ true };

		while (str[ind2] != ' ') {
			++step2;
			step = step2;

			subStr += str[ind2];
			++ind2;
			space = false;
		}

		if (!space) {
			arr[ind] = stoi(subStr.c_str());
			++ind;
		}

		i += step;
	}
}
//поиск количества инверсий для числа под нужным индексом
int findNumInvers(int* arr, int ind) {
	if (ind == 0) {
		return 0;
	}
	else {
		int kolvo{ 0 };
		for (int i{ ind - 1 }; i >= 0; --i) {
			if (arr[i] > arr[ind]) {
				++kolvo;
			}
		}
		return kolvo;
	}
}

bool isEmpty(int ind, int* arr) {
	if (arr[ind] != 0) {
		return false;
	}
	return true;
}
void sdvigToRight(int* arr, int indNach, int dlina) {
	for (int i{ dlina - 1 }; i > indNach; --i) {
		arr[i] = arr[i - 1];
	}
}

int findMax(int* arr, int dlina) {
	int max{ INT16_MIN };
	for (int i{ 0 }; i < dlina; ++i) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

string createPerest(int nachEl, int* tableInvers, int dlina) {
	string perestStroka{ "" };
	int* perest = new int[dlina] {0};

	for (int i{ dlina - 1 }; i >= 0; --i) {
		int indVstavka = tableInvers[i];
		if (isEmpty(indVstavka, perest)) {
			perest[indVstavka] = nachEl;
		}
		else {
			sdvigToRight(perest, indVstavka, dlina);
			perest[indVstavka] = nachEl;
		}
		--nachEl;
	}
	for (int i{ 0 }; i < dlina; ++i) {
		perestStroka += to_string(perest[i]) + ' ';
	}
	return perestStroka;
}

void writingFile(string str) {
	ofstream file("output.txt");
	file << str;
	file.close();
}