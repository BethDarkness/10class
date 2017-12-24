#include <iostream>
using namespace std;

class vector_double {
    double* arr;
    int size;
    int cap;
    public:
       vector_double (int new_size){
           cap=new_size;
           size=0;
           arr = new double [new_size];
       }
       ~vector_double() {
           delete [] arr;
       }
       void append (int new_size) {
           double* temp = new double (new_size);
           for (int i=0; i<cap; i++){
               temp[i]=arr[i];
           }
           delete [] arr;
           arr=temp;
           cap=new_size;
        }
        void push_back (double data) {
            if (size != cap){
                arr[size]=data;
            }
            else {
                int new_size=2*cap;
                double* temp = new double [new_size];
                for (int i=0; i<cap; i++){
                    temp[i]=arr[i];
                }
                delete [] arr;
                arr=temp;
                arr[cap]=data;
                cap=new_size;
            }
            size++;
        }
        const double& operator [] (int i) {
            if (i>=cap) {
                return arr[0];
            }
            if (i>size) {
                return 0;
            }
            return arr[i];
        }
        double pop_back() {
            double* temp = new double [cap];
            size--;
            for (int i=0; i<size; i++){
                temp[i]=arr[i];
            }
            double a=arr[size];
            delete [] arr;
            arr=temp;
            return a;
        }
};
        
int main() {
    return 0;
}
