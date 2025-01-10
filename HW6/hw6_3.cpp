#include <iostream>
using namespace std;

// 計算字串長度
int strlen(char str[]) {
    int i = 0;  
    while (str[i] != '\0') { 
        i++; 
    }
    return i;  
}

// 字元轉整數
int charToDigit(char c) {
    return c - '0';  
}

// 計算 10 的補數
void tenComplement(int num[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        num[i] = 9 - num[i];
    }
    int carry = 1;
    for (int i = n - 1; i >= 0; i--) {
        num[i] += carry;
        carry = num[i] / 10;
        num[i] %= 10;
    }
} 

// 將字串轉成 int 陣列
void stringToIntArray(char str[], int num[], int space) {
    int len = strlen(str);        

    // 初始化
    for (int i = 0; i < space; i++) {
        num[i] = 0;
    }

    // 將字串轉成整數陣列
    int index = space - 1;         
    for (int i = len - 1; i >= 0; i--) {
        if (str[i] == '-') {      
            continue;
        }
        num[index] = charToDigit(str[i]); 
        index--;
    }

    // 如果是負數，轉成 10 的補數
    if (str[0] == '-') {
        tenComplement(num, space);
    }
}

// 實作大數加法
void bigIntAdd(int num1[], int num2[], int result[], int space) {
    int carry = 0;
    for (int i = space - 1; i >= 0; i--) {
        result[i] = num1[i] + num2[i] + carry;
        carry = result[i] / 10;
        result[i] %= 10;
    }
}

// 實作大數減法
void bigIntSub(int num1[], int num2[], int result[], int space) {
    int borrow = 0;
    for (int i = space - 1; i >= 0; i--) {
        result[i] = num1[i] - num2[i] - borrow;
        if (result[i] < 0) {
            result[i] += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
    }
}

// 輸出結果，帶有負數處理與千分位
void printBigNumber(int num[], int space) {
    cout << "$";

    // 如果最高位 (num[0]) 為 9，表示是負數 (10 的補數)
    if (num[0] == 9) {
        cout << "-";
        // 恢復原本正數
        tenComplement(num, space);
    }

    // 跳過前導 0
    bool startPrint = false;
    for (int i = 0; i < space; i++) {
        if (num[i] != 0) {
            startPrint = true;
        }
        if (startPrint) {
            int digitPos = space - i;  // 從右往左的位數
            cout << num[i];
            // 每三位插入逗號
            if (digitPos % 3 == 1 && digitPos > 3) {
                cout << ",";
            }
        }
    }

    // 如果都是 0，輸出最後一位
    if (!startPrint) {
        cout << num[space - 1];
    }
}

// 主程式
int main() {
    // 讀入兩個大數 (字串型態)
    char str1[200], str2[200];
    cin >> str1 >> str2;

    // 找出較長的長度
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int maxLen = (len1 > len2 ? len1 : len2);

    // 給多一位 (可能進位)
    int space = maxLen + 1;

    // 準備四個陣列：num1, num2, sum, diff
    int *num1 = new int[space];
    int *num2 = new int[space];
    int *sum  = new int[space];
    int *diff = new int[space];

    // 初始化 + 轉成 int 陣列
    stringToIntArray(str1, num1, space);
    stringToIntArray(str2, num2, space);

    // 進行大數加法
    bigIntAdd(num1, num2, sum, space);
    // 進行大數減法
    bigIntSub(num1, num2, diff, space);

    // 輸出結果
    // 1) 加法結果
    printBigNumber(sum, space);
    cout << "\n";
    // 2) 減法結果
    printBigNumber(diff, space);
    cout << "\n";

    // 釋放記憶體
    delete[] num1;
    delete[] num2;
    delete[] sum;
    delete[] diff;

    return 0;
}




