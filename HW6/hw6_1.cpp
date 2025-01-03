#include <iostream>
using namespace std;

// input: 3 digit integers
// output: the biggest number
int main() {
    int input;
    cin >> input;

    // find the hundreds, tens, and ones digit
    // store them in an array
    int digits[3];
    for (int i = 0; i < 3; i++) {
        digits[i] = input % 10;  
        input /= 10;          
    }

    // implement bubble sort
    for (int i = 2; i > 0; i--) {  
        for (int j = 0; j < i; j++) {
            if (digits[j] < digits[j + 1]) { 
                int temp = digits[j];
                digits[j] = digits[j + 1];
                digits[j + 1] = temp;
            }
        }
    }

    // calculate the maximum number
    int maxNum = 100 * digits[0] + 10 * digits[1] + digits[2];
    cout << maxNum << endl;

    return 0;
}
