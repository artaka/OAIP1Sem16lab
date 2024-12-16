//var5
#include <iostream>
#include <Windows.h>
#include <vector>
using namespace std;

void task1(int* A[], int k, int n) {
	vector<pair<int, int>> nums;
	pair<int, int> data;//{num:rowIndex}

	for (int i = 0;i != k;++i) {
		int min = A[i][0];
		for (int j = 1;j != n;++j) {
			if (A[i][j] < min) {
				min = A[i][j];
			}
		}
		data = make_pair(min, i);
		nums.push_back(data);
	}

	int max = nums[0].first;
	int maxRow = nums[0].second;
	for (int i = 1;i != nums.size();++i) {
		if (nums[i].first > max) {
			max = nums[i].first;
			maxRow = nums[i].second;
		}
	}

	cout << "Row index: " << maxRow;
}

void task2(char arr[], int len, char sym) {
	int counter = 0;
	for (int i = 0;i != len;++i) {
		if (arr[i] == sym) {
			++counter;
		}
	}
	cout << "Count: " << counter << endl;
}

int main() {
	setlocale(LC_ALL, "RU");
	SetConsoleCP(1251);

	int choice;
	int k, n;
	char sym = ' ';
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
			cout << "Введите k: ";
			cin >> k;
			cout << "Введите n: ";
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

			task1(A, k, n);

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

			cout << "Введите символ для поиска: ";
			cin >> sym;

			task2(str, size, sym);

			delete[] str;
			break;
		case 3:  break;
		}
	} while (choice != 3);

}