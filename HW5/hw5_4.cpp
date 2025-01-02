#include <iostream>
using namespace std;

// 找到擁有獨特元素的 subset
bool must_choose(const bool** subset, int n, int m, int i) {
    // 檢查第 i 個 subset 是否包含獨特元素
    for (int j = 0; j < m; j++) {
        if (subset[i][j]) {
            bool is_unique = true;
            for (int k = 0; k < n; k++) {
                if (k != i && subset[k][j]) {
                    is_unique = false;
                    break;
                }
            }
            if (is_unique) {
                return true;
            }
        }
    }
    return false;
}

// 找到最有效率的 subset
int most_efficient_subset(const bool** subset, const bool* selected_elements, const bool* selected_subset, const int* subset_cost, int n, int m) {
    int min_per_element = 10000;
    int most_efficient_subset = -1;
    for (int i = 0; i < n; i++) {
        if (selected_subset[i]) continue;
        int num_covered = 0;
        for (int j = 0; j < m; j++) {
            if (subset[i][j] && !selected_elements[j]) {
                num_covered++;
            }
        }
        if (num_covered == 0) {
            continue;
        }
        int per_element = subset_cost[i] / num_covered;
        if (per_element < min_per_element) {
            min_per_element = per_element;
            most_efficient_subset = i;
        }
    }
    return most_efficient_subset;
}

// 更新已選擇的元素和子集合
void update(const bool** subset, bool* selected_elements, bool* selected_subset, const int* subset_cost, int n, int m, int updated_subset, int& total_cost) {
    for (int i = 0; i < m; i++) {
        if (subset[updated_subset][i]) {
            selected_elements[i] = true;
        }
    }
    selected_subset[updated_subset] = true;
    total_cost += subset_cost[updated_subset];
}

int main() {
    int n, m;
    cin >> n >> m;

    // 動態分配記憶體
    bool** subset = new bool*[n];
    for (int i = 0; i < n; i++) {
        subset[i] = new bool[m]();
    }

    for (int i = 0; i < n; i++) {
        int subset_length;
        cin >> subset_length;
        for (int j = 0; j < subset_length; j++) {
            int element;
            cin >> element;
            subset[i][element - 1] = true;
        }
    }

    char* subset_name = new char[n];
    for (int i = 0; i < n; i++) {
        cin >> subset_name[i];
    }

    int* subset_cost = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> subset_cost[i];
    }

    bool* selected_elements = new bool[m]();
    bool* selected_subset = new bool[n]();

    int total_cost = 0;

    // 選擇必要的子集合
    for (int i = 0; i < n; i++) {
        if (must_choose((const bool**)subset, n, m, i)) {
            cout << subset_name[i] << " ";
            update((const bool**)subset, selected_elements, selected_subset, subset_cost, n, m, i, total_cost);
        }
    }

    // 選擇最有效的子集合直到覆蓋所有元素
    while (true) {
        bool all_covered = true;
        for (int i = 0; i < m; i++) {
            if (!selected_elements[i]) {
                all_covered = false;
                break;
            }
        }
        if (all_covered) {
            break;
        }

        int selected_subset_index = most_efficient_subset((const bool**)subset, selected_elements, selected_subset, subset_cost, n, m);
        if (selected_subset_index == -1) {
            break;
        }

        cout << subset_name[selected_subset_index] << " ";
        update((const bool**)subset, selected_elements, selected_subset, subset_cost, n, m, selected_subset_index, total_cost);
    }

    cout << "\nTotal Cost: " << total_cost << endl;

    // 釋放記憶體
    for (int i = 0; i < n; i++) {
        delete[] subset[i];
    }
    delete[] subset;
    delete[] subset_name;
    delete[] subset_cost;
    delete[] selected_elements;
    delete[] selected_subset;

    return 0;
}
