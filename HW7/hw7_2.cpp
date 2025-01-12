#include <iostream>
using namespace std;



int submatrix_sum(int size, int** matrix) {
    int count = 0;

    for (int i = 0; i < size; i++) { 
        for (int row = 0; row < size - i; row++) {
            for (int col = 0; col < size - i; col++) {
                int sum = 0; 

                // calculate the sum of submatrix
                for (int j = 0; j <= i; j++) {
                    for (int k = 0; k <= i; k++) {
                        sum += matrix[row + j][col + k];
                    }
                }
                if (sum == 0) {
                    count++;
                }
            }
        }
    }

    return count;
}








// given number of n, nxn matrix
// calculate the number of matrix which its sum are equal to 0
// calculate the submatrix sum from 1x1 to nxn


int main(){
    int n;
    cin >> n;

    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    int sum =0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            sum += matrix[i][j];
        }
    }

    cout << submatrix_sum(n, matrix) <<","<< sum << endl;
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}