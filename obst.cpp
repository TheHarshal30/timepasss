#include<bits/stdc++.h>
using namespace std;

int sum(int freq[], int i, int j){
    int cost = 0;
    for(int k=i;k<=j;k++) cost += freq[k];
    return cost;
}

int cost(int freq[], int i, int j){
    if(j<i) return 0;
    if (j==i) return freq[i];
    int min = INT_MAX;
    int fsum = sum(freq,i,j);
    for(int k=i;k<=j;k++){
        int fcost = cost(freq,i,k-1) + cost(freq,k+1,j);
        if(fcost < min) min = fcost; 
    }
    return fsum + min;
}

int main(){
     int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys) / sizeof(keys[0]);
    cout << "Cost of Optimal BST is " << cost(freq,0, n-1);
    return 0;
}