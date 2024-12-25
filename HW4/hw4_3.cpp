#include <iostream>
using namespace std;

// check if there is continuous seats for the passenger function
// if there is ,update the seat array using the passenger's get on and get off station
// fill the array with passenger's id
bool update_cons_seats(int seats[][10], int n, int m, int on, int off, int id) {
    for (int i = 0; i < n; i++) {
        bool canUpdate = true;
        
        // 檢查該排座位是否在範圍內連續空座位
        for (int j = on; j < off; j++) {
            if (seats[i][j] != 0) {
                canUpdate = false;
                break;
            }
        }
        
        // 如果可以更新該排座位，則執行更新
        if (canUpdate) {
            for (int j = on; j < off; j++) {
                seats[i][j] = id;
            }
            return true; // 成功分配座位
        }
    }
    return false; // 沒有找到合適的座位
}

// update seats  if there is empty seats
// seats deosn't need to be continuous

bool update_fragmented_seats(int seats[][10], int n, int m, int on, int off, int id) {
    for (int j = on; j < off; j++) { // 從上車站到下車站逐列檢查
        bool assigned = false; // 標記是否找到空座位

        for (int i = 0; i < n; i++) { // 檢查所有排在該車站的座位
            if (seats[i][j] == 0) { // 如果座位空閒
                seats[i][j] = id;   // 分配座位給乘客
                assigned = true;    // 標記該車站已找到座位
                break;              // 跳出當前排的檢查
            }
        }

        // 如果該車站沒有空座位，則無法完成分配
        if (!assigned) {
            return false;
        }
    }

    return true; // 成功分配所有需求座位
}





int main(){
    int n, m, k;
    cin >> n >> m >> k;

    const int MAX_STATIONS = 10;
    const int MAX_SEATS = 10;
    int seats[MAX_SEATS][MAX_STATIONS] = {0};

    for(int i = 0; i < k; i++){
        int on, off;
        cin >> on >> off;

        bool updated = update_cons_seats(seats, n, m, on, off, i + 1);
        if(!updated){
            updated = update_fragmented_seats(seats, n, m, on, off, i + 1);
        }
        if(!updated){
            cout << "乘客 " << i + 1 << " 無法分配座位。" << endl;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }
}
