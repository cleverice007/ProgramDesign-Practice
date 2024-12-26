#include <iostream>
using namespace std;





int main(){
    // get number of nodes and edges from input
    int n, m;
    cin >> n >> m;
    const int max_Nodes = 20;
   
    // create degree array
    int degree[max_Nodes] = {0};


    for(int i=0; i<m; i++){
       int edge1, edge2;
       cin >> edge1 >> edge2;
       degree[edge1-1]++;
       degree[edge2-1]++;
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