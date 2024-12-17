#include <iostream>
using namespace std;

// clang++ -std=c++14 -stdlib=libc++ -g /Users/yanyuming/Documents/GitHub/ProgramDesign_HW/HW2/hw2_1.cpp -o hw2_1


int main(){
    int x=0, p1=0, p2=0, p3=0, y = 0;
    cin >> x >> p1 >> p2 >> p3 >> y;
    int first = 0, second = 0, third = 0; 
    int remain = x;

    if (remain >= p1){
        remain -= p1;
        first++;
    }
    if (remain >= p2){
        remain -= p2;
        second++;
    }
    if (remain >= p3 * y){
        remain -= p3 * y;
        third += y;
    }
    else{
        third = remain / p3;
        remain -= third * p3;
    }
    cout << first << " " << second << " " << third << " " << remain << endl;
}
