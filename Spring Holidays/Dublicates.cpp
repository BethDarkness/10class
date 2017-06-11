#include <iostream>

using namespace std;

void delete_duplicates(int* Array, int lenght) {
	int tmp = 0;
	for (int i = 0; i < lenght; i++) {
		for (int j = i + 1; j < lenght; j++) {
			 if (Array[i] == Array[j]) {
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
	delete_duplicates(Array, lenght);
	system("pause");
	return 0;
}