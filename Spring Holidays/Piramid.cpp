#include <iostream>
#include <conio.h>

using namespace std;

void build_ziggurat(int** Ziggurat, int counter, int lenght) {
	int pos = 0;
	int number = lenght;
	for (int i = 0; i < counter; i++) {
		for (int j = pos; j < number; j++) {				//fill upper and down stage
			Ziggurat[pos][j] = i;
			Ziggurat[lenght - pos - 1][j] = i;
		}
		for (int j = pos; j < number; j++) {				//fill side stages
			Ziggurat[j][pos] = i;
			Ziggurat[j][lenght - pos - 1] = i;
		}
		pos++;
		number--;
	}
	for (int i = 0; i < lenght; i++) {						//output Array
		for (int j = 0; j < lenght; j++) {
			cout << Ziggurat[j][i] << " ";
		}
		cout << endl;
	}
}

int main() {
	setlocale(0, "Russian");
	int lenght = 5;
	int counter;
	cin >> lenght;
	int** Ziggurat = new int*[lenght];		//create Array
	for (int i = 0; i < lenght; i++) {
		Ziggurat[i] = new int[lenght];
	}
	counter = (lenght / 2) + (lenght % 2);		//number of stages
	build_ziggurat(Ziggurat, counter, lenght);


	system("pause");
	return 0;
}