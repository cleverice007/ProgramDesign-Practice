#include <iostream>
#include <cstring>
using namespace std;

const int MAX_SIZE = 100;

int calculateScore(char* X, char* Y) {
    // Rule 1: 完全相等
    if (strcmp(X, Y) == 0) {
        return 10000;
    }

    // Rule 2: Y 是 X 的子字串
    int count = 0;
    char* pos = X;

    while ((pos = strstr(pos, Y)) != nullptr) {
        count++;
        pos += 1;  // 向後移動一位，避免重複計算相同位置    
    }

    if (count > 0) {
        return 1000 + count;
    }


    // Rule 3: 找 Y 的最長子字串出現在 X 中
    int maxLen = 0;
    int yLen = strlen(Y);
    for (int len = yLen; len >= 1; len--) {  // 由長到短檢查 Y 的子字串
        for (int start = 0; start <= yLen - len; start++) {
            char subStr[MAX_SIZE];
            strncpy(subStr, Y + start, len);
            subStr[len] = '\0';
            if (strstr(X, subStr) != nullptr) {
                maxLen = len;
                break;  // 找到最長的就跳出
            }
        }
        if (maxLen > 0) break;
    }

    return maxLen * 10;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();  // 忽略換行符，以正確讀取字符串

    char** X = new char*[n];
    for (int i = 0; i < n; i++) {
        X[i] = new char[MAX_SIZE];
        cin.getline(X[i], MAX_SIZE);
    }

    char Y[MAX_SIZE];
    cin.getline(Y, MAX_SIZE);

    int* scores = new int[n];

    for (int i = 0; i < n; i++) {
        scores[i] = calculateScore(X[i], Y);
    }

    // 以逗號分隔輸出
    for (int i = 0; i < n; i++) {
        cout << (i == 0 ? "" : ",") << scores[i];
    }
    cout << endl;

    // 釋放記憶體
    for (int i = 0; i < n; i++) {
        delete[] X[i];
    }
    delete[] X;
    delete[] scores;

    return 0;
}
