#include <iostream>
#include <cmath>
#include <climits>
using namespace std;


int main(){
     //訂貨目標, 貨量臨界, 單一存貨成本, 單一缺貨成本, 存貨量, n天
    int S, best_s = INT_MAX, c_o, c_u, I, n;
    
    cin >> S >> c_o >> c_u >> I ;
    cin >> n;

    int* d = new int[n];

    for(int i = 0; i < n; i++){
        cin >> d[i];
    }
    int minCost = INT_MAX;

    for(int s=0; s < S;s++){
        int totalCost = 0;
        int currentI = I;

        for(int i = 0; i < n; i++){
            I -= d[i];
            if(I>=0){
                totalCost += c_o*d[i];
            }
            else{
                totalCost += c_u*abs(i);
            }
            if(currentI<=s){
                currentI = S;      
            }
        }
        if(totalCost < minCost){
            best_s = s;
            minCost = totalCost;
        }
    }
    cout << best_s << "," << minCost;
}