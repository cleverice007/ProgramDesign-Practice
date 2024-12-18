#include <iostream>
#include <cmath>
using namespace std;

int main(){
    //訂貨目標, 貨量臨界, 單一存貨成本, 單一缺貨成本, 存貨量, n天
    int S = 0, s=0, c_o=0, c_u=0, I=0, n=0;

    cin >> S >> s >> c_o >> c_u >> I ;
    cin >> n;

    // 訂貨量
    int *d = new int[n];
    int days = 0, totalCost = 0;

    for(int i = 0; i < n; i++){
        cin >> d[i];
        I -= d[i];
        if(I>=0){
            totalCost += c_o*d[i];
        }
        else{
            totalCost += c_u*abs(I);
            days++;
        }
        if(I<s){
            I = S;      
             }
    }
    cout << days << "," << totalCost;
}