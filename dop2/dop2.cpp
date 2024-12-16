//-3
#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void task1(int* A[], int a, int k, int n) {
	int col = 0;
	for (int i = 0;i != k;++i) {
		for (int j = 0;j != k;++j) {
			if (A[j][i] == a) {
				col = i;
				break;
			}
		}
	}

	cout << "Col index: " << col << endl;

	for (int i = 0;i != k;++i) {
		for (int j = 0;j != n;++j) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}

void task2(char str[], int size) {
	vector<string> words;
	stringstream ss(str);
	string word;

	// Разбиваем строку на слова
	while (ss >> word) {
		words.push_back(word);
	}

	int wordCount = words.size();

	// Проверяем, четное ли количество слов
	if (wordCount % 2 == 0 && wordCount > 1) {
		int mid1 = wordCount / 2 - 1;  // Индекс первого центрального слова
		int mid2 = wordCount / 2;      // Индекс второго центрального слова

		// Меняем местами центральные слова
		std::swap(words[mid1], words[mid2]);

		// Составляем строку обратно
		string result;
		for (int i = 0; i < wordCount; ++i) {
			result += words[i];
			if (i < wordCount - 1) {
				result += " ";
			}
		}

		// Копируем результат обратно в исходную строку
		strncpy_s(str, size, result.c_str(), size-1);
		str[size - 1] = '\0';  // Завершаем строку
	}

	cout << "Результат: " << str << endl;

}

int main() {
	setlocale(LC_ALL, "RU");
	SetConsoleCP(1251);

	int choice;
	int k, n, a;
	char okon[3] = "ая";
	do
	{
		cout << "Выберите Задание:" << endl;
		cout << "1 - Задание 1" << endl;
		cout << "2 - Задание 2" << endl;
		cout << "3 - выход" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			int** A;
			cout << "Введите n: ";
			cin >> k;
			cout << "Введите m: ";
			cin >> n;
			A = new int* [k];
			for (int i = 0; i != k; i++)
			{
				A[i] = new int[n];
			}

			for (int i = 0;i != k;++i) {
				for (int j = 0;j != n;++j) {
					cout << "A[" << i << "][" << j << "]: ";
					cin >> A[i][j];
				}
			}

			cout << "Введите k: ";
			cin >> a;


			task1(A, a, k, n);

			for (int i = 0; i != k; i++)
			{
				delete[] A[i];
			}
			delete[] A;
			break;
		case 2:
			char* str;
			int size;
			cout << "Введите размер строки: ";
			cin >> size;
			cin.ignore();
			str = new char[size + 1];

			cin.getline(str, size + 1);

			str[size] = '\0';

			task2(str, size + 1);

			delete[] str;
			break;
		case 3:  break;
		}
	} while (choice != 3);

}