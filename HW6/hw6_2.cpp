#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void Permutation(int number[], int numCombination[], int start, int end, int &count) {
    if (start == end) {
        numCombination[count] = number[0] * 100 + number[1] * 10 + number[2];
        count++;
        return;
    }

    for (int i = start; i < end; i++) {
        swap(number[start], number[i]);

        Permutation(number, numCombination, start + 1, end, count);

        swap(number[start], number[i]);
    }
}

// implement bubble sort
void sort(int numCombination[], int n){
   for(int i =n-1; i<2;i--){
    for(int j=0;j<i;j++){
        if(numCombination[j]<numCombination[j+1]){
            swap(numCombination[j],numCombination[j+1]);
        }
    }
   }
}



// giving 3 digits number, find the kth largest number

int main(){
    int input, k, number[3];
    cin >> input >> k;
    
    for(int i = 0; i < 3; i++){
        number[i] = input % 10;
        input /= 10;
    }

    int count = 0;
    int numCombination[6];
    Permutation(number, numCombination, 0, 3, count);
    sort(numCombination, 6);
    cout << numCombination[k-1] << endl;
}