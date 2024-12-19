#include <iostream>
using namespace std;

int main() {
    // 輸入數字 n
    int n = 0;
    cin >> n;

    // 初始化，控制輸出格式
    bool first = true;

    for (int i = 2; i <= n; i++) {
        int power = 0; // 計算次數

        // 判斷是否為質因數
        while (n % i == 0) {
            n /= i;
            power++;
        }

        // 如果 `power > 0` 表示 i 是質因數
        if (power > 0) {
            if (!first) {
                cout << " * "; // 非第一個質因數前加 `*`
            }
            cout << i; // 輸出質因數
            if (power > 1) {
                cout << "^" << power; // 如果次數大於 1，輸出次數
            }
            first = false; // 第一個質因數已處理
        }
    }

    return 0;
}
