#include <iostream>
using namespace std;


int main(){
    int n = 0;
    int t = 0;

    cin >> n >> t;
    int *x = new int[n];

    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    int sum = 0;
    int count = 0;
    int avg = 0;
    int max = 0;

     for (int i = 0; i < n; i++)
    {
        if (x[i] > max)
        {
            max = x[i];
        }

        if (x[i] >= t)
        {
            sum += x[i];
            count++;
        }
    }

    cout << max << "," << (count > 0 ? sum / count : -1);
}
