#include <iostream>
#include <conio.h>

using namespace std;

void put_snake(int** Array, int lenght_x, int lenght_y) {
	int y = 0;		//coordinates
	int x = 0;
	int counter = lenght_x*lenght_y;
	while (counter > 1) {		//main cycle
		for (y = y; y < lenght_y; y++) {		//move down
			if (y + 1 == lenght_y) {
				break;
			}
			if (Array[y + 1][x] != 0) {
				break;
			}
			else
				Array[y][x] = counter;
			counter--;
		}
		for (x = x; x < lenght_x; x++) {		//move right
			if (Array[y][x + 1] != 0) {
				break;
			}
			if (x + 1 == lenght_x) {
				break;
			}
			else
				Array[y][x] = counter;
			counter--;
		}
		for (y = y; y > 0; y--) {				//move up
			if (Array[y - 1][x] != 0) {
				break;
			}
			if (y == 0) {
				break;
			}
			else
				Array[y][x] = counter;
			counter--;
		}
		for (x = x; x > 0; x--) {				//move left
			if (Array[y][x - 1] != 0) {
				break;
			}
			if (x - 1 == 0) {
				break;
			}
			else
				Array[y][x] = counter;
			counter--;
		}

	}
	for (int i = 0; i < lenght_y; i++) {			//output array
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
	int** Array = new int*[lenght_y];			//create Array
	for (int i = 0; i < lenght_y; i++) {
		Array[i] = new int[lenght_x];
	}
	for (int i = 0; i < lenght_y; i++) {		//fill Array with 0
		for (int j = 0; j < lenght_x; j++) {
			Array[i][j] = 0;
		}
	}
	put_snake(Array, lenght_x, lenght_y);
	system("pause");
	return 0;
}