#include <iostream>
using namespace std;


int main(){
    // get number of nodes from input 
    // and create adjacency matrix
    const int max_Nodes = 20;
    int matrix[max_Nodes][max_Nodes] = {0};
    int n;
    cin >> n;

    // get the adjacency matrix from input
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> matrix[i][j];
        }
    }
    // create the degree array
    int degree[max_Nodes] = {0};
    // calcaulte the degree of each node
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            degree[i] += matrix[i][j];
        }
    }

    // print the degree of each node and count the odd degree nodes
    // if the number of odd degree nodes is over 4, print 1 else 0
    int odd_degree_count = 0;
    for(int i=0; i<n; i++){
        cout << (i == 0 ? "" : ",") << degree[i];
        if(degree[i] % 2 == 1){
            odd_degree_count++;
        }
    }
    cout << ";" <<(odd_degree_count >= 4 ? 1 : 0);
}