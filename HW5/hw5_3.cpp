#include <iostream>
using namespace std;

const int MAX_N = 25, MAX_M = 100;

// 計算最有效的子集合
int most_efficient_subset(int selected_elements[], int subset[][MAX_M], int subset_cost[], int n, int m) {
    int min_per_element = 10000; // 初始設為較大值
    int most_efficient_subset = -1; // 初始化為無效索引

    for (int i = 0; i < n; i++) {
        int num_covered = 0; // 記錄該子集合能覆蓋的未選擇元素數量
        for (int j = 0; j < m; j++) {
            if (subset[i][j] == 1 && selected_elements[j] == 0) {
                num_covered++; // 增加覆蓋的未選擇元素數量
            }
        }

        if (num_covered == 0) {
            continue; // 如果該子集合不覆蓋任何新元素，跳過
        }

        int per_element = subset_cost[i] / num_covered; // 計算每覆蓋一個元素的成本
        if (per_element < min_per_element) {
            min_per_element = per_element; // 更新最小成本
            most_efficient_subset = i;    // 更新效率最高的子集合索引
        }
    }

    return most_efficient_subset; // 返回效率最高的子集合索引
}

// 更新已選擇的元素和子集合
void update(int selected_elements[], int subset[][MAX_M], int selected_subset[], int m, int most_efficient_subset, int subset_cost[], int& total_cost) {
    for (int i = 0; i < m; i++) {
        if (subset[most_efficient_subset][i] == 1) {
            selected_elements[i] = 1; // 標記該元素為已選擇
        }
    }

    selected_subset[most_efficient_subset] = 1; // 標記該子集合為已選擇
    total_cost += subset_cost[most_efficient_subset]; // 累加總成本
}

int main() {
    int n, m;
    cin >> n >> m;

    // 初始化數據結構
    int selected_elements[MAX_M] = {0}; // 記錄已選擇的元素
    int selected_subset[MAX_N] = {0};   // 記錄已選擇的子集合
    int total_cost = 0;                 // 總成本

    int subset[MAX_N][MAX_M] = {0}; // 子集合與元素的關係
    char subset_name[MAX_N] = {0};  // 子集合名稱
    int subset_cost[MAX_N] = {0};   // 子集合成本

    // 輸入子集合包含的元素
    for (int i = 0; i < n; i++) {
        int num_elements;
        cin >> num_elements;
        for (int j = 0; j < num_elements; j++) {
            int element;
            cin >> element;
            subset[i][element - 1] = 1; // 元素索引從 0 開始
        }
    }

    // 輸入子集合名稱
    for (int i = 0; i < n; i++) {
        cin >> subset_name[i];
    }

    // 輸入子集合成本
    for (int i = 0; i < n; i++) {
        cin >> subset_cost[i];
    }

    // 選擇子集合直到覆蓋所有元素
    while (true) {
        int selected_subset_index = most_efficient_subset(selected_elements, subset, subset_cost, n, m);
        if (selected_subset_index == -1) {
            break; // 如果沒有有效的子集合可選，結束
        }

        // 輸出選擇的子集合名稱
        cout << subset_name[selected_subset_index] << " ";

        // 更新已選擇的元素和子集合
        update(selected_elements, subset, selected_subset, m, selected_subset_index, subset_cost, total_cost);

        // 檢查是否覆蓋了所有元素
        bool all_covered = true;
        for (int i = 0; i < m; i++) {
            if (selected_elements[i] == 0) {
                all_covered = false;
                break;
            }
        }
        if (all_covered) {
            break; // 所有元素已覆蓋，結束
        }
    }

    // 輸出總成本
    cout << "\nTotal Cost: " << total_cost << endl;

    return 0;
}