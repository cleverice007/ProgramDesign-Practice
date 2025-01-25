#include <iostream>
#include <cmath>
#include <cctype>
#include <cstring>
#include <cstdlib>
using namespace std;

const int Max_length = 100;

// create LogisticCenter struct
struct LogisticCenter{
    int x;
    int y;
};

// create RetailStore struct
struct RetailStore{
    int x;
    int y;
    int demand;
    int replenishment;
};

// return the distance between logistic center and retail store
int calc_distance(LogisticCenter* logistic_center, RetailStore* retail_store){
    return abs(logistic_center->x - retail_store->x) + abs(logistic_center->y - retail_store->y);
}

// clean up the input, only store digits and ','
void cleanInput(char* input, char* output){
    while(*input){
        if(*input ==','|| isdigit(*input)){
            *output = *input;
            output++;
        }
        input++;
    }
}

int main(){
    int n, m, p, f;

    char *line1 = new char[Max_length];
    char *line1_digit = new char[Max_length];
    cin.getline(line1, Max_length);
    cleanInput(line1, line1_digit);

    // parse the input: n, m, p, f
    char *token;
    int count = 0;

    token = strtok(line1_digit, ",");
    while (token != NULL) {
        if (count == 0)
            n = atoi(token);
        else if (count == 1)
            m = atoi(token);
        else if (count == 2)
            p = atoi(token);
        else
            f = atoi(token);

        token = strtok(NULL, ",");
        count++;
    }

    // create array of logistic centers and retail stores
    LogisticCenter *logistic_centers = new LogisticCenter[n];
    RetailStore *retail_stores = new RetailStore[m];

    // read logistic center coordinates
    char *line2 = new char[Max_length];
    char *line2_digit = new char[Max_length];
    cin.getline(line2, Max_length);
    cleanInput(line2, line2_digit);

    for(int i = 0; i < 2 * n; i += 2){
        logistic_centers[i/2].x = atoi(&line2_digit[i]);
        logistic_centers[i/2].y = atoi(&line2_digit[i+1]);
    }

    // read retail store coordinates
    char *line3 = new char[Max_length];
    char *line3_digit = new char[Max_length];
    cin.getline(line3, Max_length);
    cleanInput(line3, line3_digit);

    for(int i = 0; i < 2 * m; i += 2){
        retail_stores[i/2].x = atoi(&line3_digit[i]);
        retail_stores[i/2].y = atoi(&line3_digit[i+1]);
    }

    // read demand of products for each retail store
    char *line4 = new char[Max_length];
    char *line4_digit = new char[Max_length];
    cin.getline(line4, Max_length);
    cleanInput(line4, line4_digit);

    for(int i = 0; i < m; i++){
        retail_stores[i].demand = atoi(&line4_digit[i]);
        retail_stores[i].replenishment = 0;  // initialize replenishment
    }

    // 查找每家零售店的最小距離物流中心，若距離相同，依 x，再依 y 排序
    for(int i = 0; i < m; i++){
       int min_distance = 1000000;
       int index        = -1;
       // 用來比較當距離相同時，誰的 x 更小或 y 更小
       int min_x        = 1000000; 
       int min_y        = 1000000; 

        for(int j = 0; j < n; j++){
            int distance = calc_distance(&logistic_centers[j], &retail_stores[i]);
            if(distance < min_distance){
                // 發現更小距離，直接更新
                min_distance = distance;
                index        = j;
                min_x        = logistic_centers[j].x;
                min_y        = logistic_centers[j].y;
            }
            else if(distance == min_distance) {
                // 距離相同時，比較 x、y
                if(logistic_centers[j].x < min_x) {
                    index        = j;
                    min_x        = logistic_centers[j].x;
                    min_y        = logistic_centers[j].y;
                }
                else if(logistic_centers[j].x == min_x && logistic_centers[j].y < min_y) {
                    index        = j;
                    min_x        = logistic_centers[j].x;
                    min_y        = logistic_centers[j].y;
                }
            }
        }

        // 判斷售價是否足以覆蓋 min_distance * f
        if(p >= min_distance * f){
            retail_stores[i].replenishment = index + 1; // 從 1 開始編號
        }

        cout << retail_stores[i].replenishment << (i != m-1 ? "," : "\n");
    }

    delete[] logistic_centers;
    delete[] retail_stores;
    delete[] line1_digit;
    delete[] line2_digit;
    delete[] line3_digit;
    delete[] line4_digit;

    return 0;
}
