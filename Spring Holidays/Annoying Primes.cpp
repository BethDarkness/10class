#include <iostream>
#include <windows.h>

using namespace std;

void delete_annoying_primes(int* Array, int lenght) {
	int tmp = 0;
	for (int i = 0; i < lenght; i++) {
		for (int j = 1; j < lenght + 1; j++) {
			if (i != j - 1 & Array[i] == Array[j - 1] & Array[i] % j != 0 & Array[i] != j) {
				tmp++;
			}
		}
		if (!tmp) {
			cout << Array[i] << endl;
		}
		else
			tmp = 0;
	}
}

int main() {
	int lenght;
	cin >> lenght;
	int* Array = new int(lenght);
	for (int i = 0; i < lenght; i++) {
		cin >> Array[i];
	}
	delete_annoying_primes(Array, lenght);

	system("pause");
	return 0;
}