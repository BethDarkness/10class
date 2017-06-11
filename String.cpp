#include <iostream>

using namespace std;

typedef class
{
    char* arr;
    public:
    string (char* a, int n)
    {
        arr = new char**[n];
        for (int i=0; i<n; i++)
        {
            arr[i]=a[i];
        }
    }
    char* get (int i)
    {
        return arr[i];
    }
    void set (char* a, int i)
    {
        arr[i]=a[i];
    }
    void print()
    {
        for (int i=0; i<n; i++)
        {
            cout<<arr[i];
        }
    }
    ~string()
    {
        for (int i=0; i<n; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }
} string;

int main ()
{
    char* a[10];
    for (int i=0; i<10; i++)
    {
        cin>>a[i];
    }
    string obj (a, 10);
    {
        cout<<obj.get(5);
        obj.set(a, 6);
        obj.print();
    }
    return 0;
}
