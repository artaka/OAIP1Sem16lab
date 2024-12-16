#include <iostream>
#include <Windows.h>
using namespace std;

void task1(int* A[], int a, int b, int k, int n) {
	int rowA = 0;
	for (int i = 0;i != k;++i) {
		for (int j = 0;j != k;++j) {
			if (A[i][j] == a) {
				rowA = i;
				break;
			}
		}
	}

	int rowB = 0;
	for (int i = 0;i != k;++i) {
		for (int j = 0;j != n;++j) {
			if (A[i][j] == b) {
				rowB = i;
				break;
			}
		}
	}

	for (int i = 0;i != n;++i) {
		int temp = A[rowB][i];
		A[rowB][i] = A[rowA][i];
		A[rowA][i] = temp;
	}

	for (int i = 0;i != k;++i) {
		for (int j = 0;j != n;++j) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}

bool isThis(char str[], char okon[], int pos) {
	int okonlen = strlen(okon) - 1;

	for (int i = pos, j = okonlen;i != pos - okonlen;--i, --j) {
		if (str[i] != okon[j]) {
			return false;
		}
	}
	return true;
}

void task2(char arr[],int len,char okonch[]) {
	int letCounter = 0;

	for (int i = 0;i != len;++i) {

		if (arr[i] == ' ' || arr[i] == '\0') {
			if (letCounter != 0) {

				if (isThis(arr, okonch, i - 1)) {
					for (int j = i - letCounter;j != i;++j) {
						cout << arr[j];
					}
					cout << endl;
				}

			}

			letCounter = 0;
		}
		else {
			++letCounter;
		}

	}
}

int main() {
	setlocale(LC_ALL, "RU");
	SetConsoleCP(1251);

	int choice;
	int k, n, a, b;
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
			cout << "Введите k: ";
			cin >> k;
			cout << "Введите n: ";
			cin >> n;
			A = new int*[k];
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

			cout << "Введите a: ";
			cin >> a;
			cout << "Введите b: ";
			cin >> b;

			task1(A, a, b, k, n);

			for (int i=0; i != k; i++)
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

			task2(str, size, okon);
			
			delete[] str;
			break;
		case 3:  break;
		}
	} while (choice != 3);

}