#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

bool is_prime (int a) {
    if (a == 0) {
        return false;
    }
    if (a == 1) {
        return false;
    }
    for (int i = 2; i < sqrt(a); i++) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}
unsigned long int GCD (unsigned long int a, unsigned long int b) {
    if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }
    return GCD (b, a % b);
}
unsigned long int binpow (unsigned long int n, unsigned long int m) {
    if (m == 0) {
        return 1;
    }
    if (m % 2 == 0) {
        unsigned long int a=binpow(n, m / 2);
        return a*a;
    }
    else {
        return binpow (n, m - 1) * n;
    }
}

void RSA(unsigned long int m) {
    int p = 0;
    int q = 0;
    while (is_prime(p)!= 1 && is_prime(q)!= 1) {
        p = 1 + rand() % 1000;
        q = 1 + rand() % 1000;
    }
    unsigned long int n = p * q;
    unsigned long int f=(p - 1) * (q - 1);
    unsigned long int e;
    do {
        e = 1 + rand() % f;
    } while(GCD(e, f) != 1);
    cout << "Prime numbers:" << p << "," << q <<endl;
    cout << "Key to encrypt:" << e << "," << n << endl;
    unsigned long int c;
    c=binpow(m, e) % n;
    cout << "Encrypted message:" << c << endl; 
    unsigned long int d; 
    do {
        d = 1 + rand() % 1000;
    } while((d * e) % f != 1);
    cout << "Key to decrypt:" << d << "," << n << endl;
    m = binpow(c, d) % n;
    cout << "Original message:" << m; 
}

int main () {
    
}
