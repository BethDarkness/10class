#include <iostream>
#include <conio.h>
#include <vector>
#include <math.h>

using namespace std;

void Eulers_formula(int a) {
	vector<int> array;
	array.resize(a);
	int number_of_numbers = a;
	for (int i = 0; i < array.size(); i++) {
		array[i] = i + 1;
	}
	for (int i = 0; i < array.size(); i++) {
		for (int j = a; j > 0; j--) {
			if (fmod(a, j) == 0 & fmod(array[i], j) == 0) {
				if (j != 1) {
					number_of_numbers--;
				}
				break;
			}
		}
	}
	cout << number_of_numbers << endl;
	
}

int main() {
	setlocale(0, "Russian");
	int a;
	cout << "‚ведите предел" << endl;
	cin >> a;
	Eulers_formula(a);
	_getch();
	return 0;
}