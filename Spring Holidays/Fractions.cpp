#include<iostream>

using namespace std;

int proper_fraction(int denom) {
	if (denom < 0) {
		denom =-denom;
	}
	if (denom == 1) {
		return 0;
	}
    return proper_fraction (denom - 1) + 1;
}

int main(void){
    int denom = 0;
    cin >> denom;
    cout << proper_fraction(denom) ;
    return 0;
}
