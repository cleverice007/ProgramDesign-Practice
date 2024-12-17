#include <iostream>
using namespace std;


int main(){
    // number of students, number of subjects
    int m = 0, k = 0;

    // student number and subjects number
    int n=0, d = 0;
    
    // subjects number for selection
    int a1 = 0, a2 =0;

    // take input as number of students and number of subjects
    cin >> m >> k;

    // take m input as student number and do nothing
    for(int i = 0; i < m; i++){
        cin >> n;
    }
    // take input as subjects number
    cin >> a1 >> a2;

    // find the number of students who enroll in one of the subjects
    int count = 0;
    for(int i =0; i < m; i++){
        int subject = 0;
        cin >> subject;
        if (subject == a1 || subject == a2){
            count++;
        }
    }
    cout << count << endl;

}