#include <iostream>
#include <cmath>
using namespace std;






int main(){

// input  number of questions  n , number of students m , minimum bar t, lowest sum score standard s
int n, m, t, s;
cin >> n >> m >> t >> s;

// calulate per students sum of scores, eliminate scores less than t
// eliminate students with sum of scores less than s and store the count
int count = 0;
for(int i = 0; i < m; i++){
    int sum = 0;
    
    for(int j = 0; j < n; j++){
        int score = 0;
        cin >> score;
        if(score >= t){
            sum += score;
        }
        if(sum >= s){
            count++;
        }
    } 
}
cout << count << endl;  
}