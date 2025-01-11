#include <iostream>
using namespace std;

void bubbleSort(int n, int num[], int ans[2]) {
    int loop = 0;      
    int exchange = 0;  

    for (int i = n - 1; i >= 0; i--) {
        int swapped = 0; 
        loop++; 
        for (int j = 0; j < i; j++) {
            if (num[j] > num[j + 1]) {
                exchange++; 
                int temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
                swapped = 1; 
            }
        }
        if (swapped == 0) { 
            break;
        }
    }
    ans[0] = loop;     
    ans[1] = exchange; 
}


// implement bubble sort
// calculate loop times and exchange times
int main() {
    int n;
    cin >> n;

    int* num = new int[n]; 
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    int ans[2] = {0, 0}; 

    bubbleSort(n, num, ans);

    cout << "loop times: " << ans[0] << endl;
    cout << "exchange times: " << ans[1] << endl;

    delete[] num; 
    return 0;
}
