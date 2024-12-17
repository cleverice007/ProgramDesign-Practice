#include <iostream>
using namespace std;


int main(){
    // student number needs to lower than 1001
    int n1 = 1001, n2 = 1001, n3 = 1001;

    // subjects number 
    int d1 = 0, d2 = 0, d3 = 0;

    // subjects number for selection
    int a1 = 0, a2 =0;

    cin >> n1 >> n2 >> n3 ;
    cin >> d1 >> d2 >> d3 ;
    cin >> a1 >> a2;

    int ans1 = 1001, ans2 = 1001, ans3 = 1001;

    if (d1 == a1 || d1 == a2){
        ans1 = n1;
    }

    if (d2 == a1 || d2 == a2){
        ans2 = n2;
    }
    
    if (d3 == a1 || d3 == a2){
        ans3 = n3;
    }

    if(ans1 > ans2){
        int temp = ans1;
        ans1 = ans2;
        ans2 = temp;
        if(ans2 > ans3){
            temp = ans2;
            ans2 = ans3;
            ans3 = temp;
        }
    }
    else{
        if(ans2 > ans3){
            int temp = ans2;
            ans2 = ans3;
            ans3 = temp;
        }
    }
    if(ans1 > 1000){
        cout << -1 << endl;
    }
    else{
        if(ans2 > 1000){
            cout << ans1 << endl;
        }
        else{
            if(ans3 > 1000){
                cout << ans1 + ans2 << endl;
            }
            else{
                cout << ans1 + ans2 + ans3 << endl;
            }
        }
    }
    
    

}