#include <iostream>
#include <cmath>
using namespace std;


// calculate body temperature
// formula = t - 2 * sqrt(s)

double bodyTemp(int t , int s ){
    return t - 2 * sqrt(s);
}

// find min body temperature and return the index

int findMinTemp(double *bodyTemps, int n){
    int minIndex = 0;
    for(int i = 1; i < n; i++){
        if(bodyTemps[i] < bodyTemps[minIndex]){
            minIndex = i;
        }
    }
    return minIndex;
}


int main(){
    // how many temperatures and speeds
    int n = 0;
    cin >> n;

    // create n arrays to store body temperature
    double *bodyTemps = new double[n];

    // input temperature and speed and calculate body temperature

    for(int i = 0; i < n; i++){
        int t = 0;
        int s = 0;
        cin >> t >> s;
        bodyTemps[i] = bodyTemp(t, s);
    }

    cout << findMinTemp(bodyTemps, n)+1 << endl;
}