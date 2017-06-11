#include <iostream>
#include <conio.h>
#include <vector>
#include <math.h>

using namespace std;

void Simple_Number(int a) {
	
	int p = 2;
	bool check = 0;
	int divider = 0;
	
	vector<int> array;								
	array.resize(a - 1);
	for (int i = 0; i < array.size(); i++) {
		array[i] = i + 2;
	}
	
	while (1) {
		if (p*p > a) {
			cout << "Простое число:1" << endl;
			for (int i = 0; i < array.size(); i++) {
				if (array[i] != 0) {
					cout << "Простое число:" << array[i] << endl;
				}
			}
			break;
		}
		if (check == 0) {
			for (int i = 0; i < array.size(); i++) {
				if (fmod(array[i], p) == 0 & array[i] != p) {
					array[i] = 0;
				}
			}
			check = 1;
		}
		if (check == 1) {
			for (int i = divider; i < array.size(); i++) {
				if (array[i] != 0 & array[i] != p) {
					p = array[i];
					divider = i + 1;
					break;
				}
			}
			check = 0;
		}
	}
}

int main() {
	setlocale(0, "Russian");
	int a;
	cout << "Введите предел" << endl;
	cin >> a;
	Simple_Number(a);
	_getch();
	return 0;
}