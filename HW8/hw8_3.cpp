#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

// 定義結構 LogisticCenter
struct LogisticCenter {
    int x;
    int y;
    int replenishment;  // 該物流中心剩餘可供貨量
};

// 定義結構 RetailStore
struct RetailStore {
    int x;
    int y;
    int demand;    // 零售店需求
    bool fulfilled; // 是否已滿足(或放棄)
};

// 尋找最小距離的物流中心
// - store 指向欲處理的零售店
// - logisticCenters 指向各個物流中心的指標陣列
// - n 是物流中心個數
// 回傳找到的物流中心索引（-1 表示找不到可供貨的物流中心）
int min_distance(const RetailStore* store, LogisticCenter* logisticCenters, int n) {
    int min_dis = 1000000;  // 用來比較的最大距離
    int min_index = -1;

    for(int i = 0; i < n; i++){
        // 只有在該中心仍有補貨量時才考慮
        if(logisticCenters[i].replenishment > 0){
            int dist = abs(logisticCenters[i].x - store->x)
                     + abs(logisticCenters[i].y - store->y);
            if(dist < min_dis){
                min_dis = dist;
                min_index = i;
            }
            // 若想加入同距離下比庫存大小，可在此擴充判斷
        }
    }

    return min_index;
}

int main() {

    // n=物流中心數, m=零售店數, p=商品售價, c=運輸成本(每單位距離)
    int n, m, p, c;
    cin >> n >> m >> p >> c;

    // 建立零售店陣列
    RetailStore* retail_stores = new RetailStore[m];
    for(int i = 0; i < m; i++){
        cin >> retail_stores[i].x >> retail_stores[i].y;
        retail_stores[i].fulfilled = false;
    }

    // 建立物流中心陣列
    LogisticCenter* logistic_centers = new LogisticCenter[n];
    for(int i = 0; i < n; i++){
        cin >> logistic_centers[i].x >> logistic_centers[i].y;
    }

    // 讀取零售店需求
    for(int i = 0; i < m; i++){
        cin >> retail_stores[i].demand;
    }

    // 讀取物流中心補貨量
    for(int i = 0; i < n; i++){
        cin >> logistic_centers[i].replenishment;
    }

    long long total_profit = 0;        // 考慮利潤可能很大, 建議用 long long
    long long unfulfilled_demand = 0;  // 未被滿足的需求量

    // 針對每個零售店，嘗試找到最近且有利潤的物流中心
    for(int i = 0; i < m; i++){
        while(!retail_stores[i].fulfilled && retail_stores[i].demand > 0){
            // 找到最近距離的物流中心
            int index = min_distance(&retail_stores[i], logistic_centers, n);

            // 若沒找到(表示物流中心皆無庫存)
            if(index == -1){
                unfulfilled_demand += retail_stores[i].demand;
                retail_stores[i].fulfilled = true;
                break;
            }

            // 計算距離與毛利
            int dist = abs(logistic_centers[index].x - retail_stores[i].x)
                     + abs(logistic_centers[index].y - retail_stores[i].y);
            int profit_margin = p - c * dist;  // 單位利潤

            // 若毛利 <= 0, 則無利可圖, 放棄該店
            if(profit_margin <= 0){
                unfulfilled_demand += retail_stores[i].demand;
                retail_stores[i].fulfilled = true;
                break;
            }
            else {
                // 可以供貨
                int can_supply = logistic_centers[index].replenishment;
                int needed = retail_stores[i].demand;

                // 供貨量
                int supply_amount = (can_supply >= needed ? needed : can_supply);

                // 計算利潤
                total_profit += (long long)supply_amount * profit_margin;

                // 更新物流中心與零售店
                logistic_centers[index].replenishment -= supply_amount;
                retail_stores[i].demand -= supply_amount;

                // 若需求降為 0, 表示店家已滿足
                if(retail_stores[i].demand == 0){
                    retail_stores[i].fulfilled = true;
                }
            }
        }
    }

    // 所有店處理完後, 輸出結果
    cout << total_profit << " " << unfulfilled_demand << endl;

    delete[] retail_stores;
    delete[] logistic_centers;

    return 0;
}
