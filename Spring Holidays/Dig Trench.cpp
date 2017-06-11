#include <iostream>
#include <windows.h>

using namespace std;

void dig_trench(int** Array, int lenght_x, int lenght_y) {
	int pos_x = 0;
	int pos_y = 0;
	int counter = 0;
	for (int i = lenght_y; i > 0; i--) {
		for (int x = pos_x; x < lenght_x; x++) {
			Array[pos_y][x] = counter;
			counter++;
		}
		counter = 0;
		for (int y = pos_y; y < lenght_y; y++) {
			Array[y][pos_x] = counter;
			counter++;
		}
		counter = 0;
		pos_x++;
		pos_y++;
	}
	for (int i = 0; i < lenght_y; i++) {
		for (int j = 0; j < lenght_x; j++) {
			cout << Array[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int lenght_x, lenght_y;
	cin >> lenght_x >>lenght_y;
	int** Array = new int*[lenght_y];
	for (int i = 0; i < lenght_y; i++) {
		Array[i] = new int[lenght_x];
	}
	dig_trench(Array, lenght_x, lenght_y);

	system("pause");
	return 0;
} 