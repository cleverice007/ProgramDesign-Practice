#include <iostream>
using namespace std;

int submatrix_sum(int size, int** matrix) {
    // 構建前綴和矩陣
    int** prefix = new int*[size];
    for (int i = 0; i < size; i++) {
        prefix[i] = new int[size];
        for (int j = 0; j < size; j++) {
            prefix[i][j] = matrix[i][j];
            if (i > 0) prefix[i][j] += prefix[i - 1][j];
            if (j > 0) prefix[i][j] += prefix[i][j - 1];
            if (i > 0 && j > 0) prefix[i][j] -= prefix[i - 1][j - 1];
        }
    }

    // 計算和為零的子矩陣數量
    int count = 0;
    for (int r1 = 0; r1 < size; r1++) {
        for (int c1 = 0; c1 < size; c1++) {
            for (int r2 = r1; r2 < size; r2++) {
                for (int c2 = c1; c2 < size; c2++) {
                    // 使用前綴和公式計算子矩陣和
                    int sum = prefix[r2][c2];
                    if (r1 > 0) sum -= prefix[r1 - 1][c2];
                    if (c1 > 0) sum -= prefix[r2][c1 - 1];
                    if (r1 > 0 && c1 > 0) sum += prefix[r1 - 1][c1 - 1];

                    // 判斷是否為零
                    if (sum == 0) count++;
                }
            }
        }
    }

    // 釋放前綴和矩陣記憶體
    for (int i = 0; i < size; i++) {
        delete[] prefix[i];
    }
    delete[] prefix;

    return count;
}

int main() {
    int n;
    cin >> n;

    // 動態分配矩陣
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // 計算矩陣總和
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += matrix[i][j];
        }
    }

    // 計算和為零的子矩陣數量
    cout << submatrix_sum(n, matrix) << "," << sum << endl;

    // 釋放記憶體
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
