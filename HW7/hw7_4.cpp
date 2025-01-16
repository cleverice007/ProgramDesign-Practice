#include <iostream>
using namespace std;

void print_prime(int n) {
    bool first = true;
    for (int i = 2; i * i <= n; i++) {
        int count = 0;
        while (n % i == 0) {           
            count++;
            n /= i;
        }
        if (count > 0) {
            if (!first) {
                cout << " * ";
            }
            cout << i;
            if (count > 1) {
                cout << "^" << count;
            }
            first = false;
        }
    }
   
    if (n > 1) {
        if (!first) {
            cout << " * ";
        }
        cout << n;
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        print_prime(i);
        cout << (i != n ? "\n" : "");
    }
}