#include <iostream>
using namespace std;

// find the min distance between logistics and shopping

int min_distance(int** logistics, int* shopping_row, int n) {
    int min_distance = 1000000; 
    for (int j = 0; j < n; j++) { 
        int distance = 0;
        for (int k = 0; k < 2; k++) { 
            distance += abs(logistics[j][k] - shopping_row[k]);
        }
        if (distance < min_distance) {
            min_distance = distance;
        }
    }
    return min_distance; 
}

int main(){
    // input : number of 物流中心、number of 購物中心
    // price of prducts
    // price of transportation
    // x ,y axis of 物流中心
    // x ,y axis of 購物中心
    // demand of 購物中心
    int n, m, p, t;
    cin >> n >> m >> p >> t;

    int** logistics = new int*[n];
    for (int i = 0; i < n; i++) {
        logistics[i] = new int[2];
        cin >> logistics[i][0] >> logistics[i][1];
    }

    int** shopping = new int*[m];
    for (int i = 0; i < m; i++) {
        shopping[i] = new int[2];
        cin >> shopping[i][0] >> shopping[i][1] ;
    }

    int* demand = new int[m];
    for(int i = 0; i < m; i++){
        cin >> demand[i];
    }
    int profit = 0;
    int total_storage = 0;
    // find the min distance between logistics and shopping
    // calculate the total profit and storage
    for(int i = 0 ; i<m; i++){
        int min_dis = min_distance(logistics, shopping[i], n);
        if(p - min_dis * t >= 0){
            profit+= demand[i] * (p - min_dis * t);
    }else{
        total_storage += demand[i];
    }
    }

    delete[] demand;
    for (int i = 0; i < n; i++) {
        delete[] logistics[i];
    }
    delete[] logistics;
    for (int i = 0; i < m; i++) {
        delete[] shopping[i];
    }
    delete[] shopping;


    cout << profit << "," << total_storage << endl;


}