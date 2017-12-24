#include <iostream>
using namespace std;

void put_snake(int** Array, int lenght_x, int lenght_y) {
	int y = 0;
	int x = 0;
	int counter = 1;
	while (counter < lenght_x * lenght_y) {
		for (y = y; y < lenght_y; y++) {
			if (y + 1 == lenght_y) {
				break;
			}
			if (Array[y + 1][x] != 0) {
				break;
			}
			else
				Array[y][x] = counter;
			counter++;
		}
		for (x = x; x < lenght_x; x++) {
			if (Array[y][x + 1] != 0) {
				break;
			}
			if (x + 1 == lenght_x) {
				break;
			}
			else
				Array[y][x] = counter;
			counter++;
		}
		for (y = y; y > 0; y--) {
			if (Array[y - 1][x] != 0) {
				break;
			}
			if (y == 0) {
				break;
			}
			else
				Array[y][x] = counter;
			counter++;
		}
		for (x = x; x > 0; x--) {
			if (Array[y][x - 1] != 0) {
				break;
			}
			if (x - 1 == 0) {
				break;
			}
			else
				Array[y][x] = counter;
			counter++;
		}

	}
	for (int i = 0; i < lenght_y; i++) {
		for (int j = 0; j < lenght_x; j++) {
			cout << Array[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int lenght_x;
	int lenght_y;
	cin >> lenght_y >> lenght_x;
	int** Array = new int*[lenght_y];
	for (int i = 0; i < lenght_y; i++) {
		Array[i] = new int[lenght_x];
	}
	for (int i = 0; i < lenght_y; i++) {
		for (int j = 0; j < lenght_x; j++) {
			Array[i][j] = 0;
		}
	}
	put_snake(Array, lenght_x, lenght_y);
	system("pause");
	return 0;
}
