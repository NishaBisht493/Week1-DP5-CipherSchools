#include<bits/stdc++.h>
using namespace std;

int rainWater(vector<int> &heights){
    int n = heights.size();
    vector<int> lMax(n), rMax(n);

    //Calculate lMax 
    lMax[0] = heights[0];
    
    for(int i = 1; i < n; i++){
        lMax[i] = max(heights[i], lMax[i - 1]);
        // rMax[n - i - 1] = max(heights[n - i - 1], rMax[n - i]);
    }

    //Calculate rMax
    rMax[n - 1] = heights[n - 1];

    for(int i = n - 2; i >= 0; i--){
        rMax[i] = max(heights[i], rMax[i + 1]);
    }

    int water = 0;
    for(int i = 1; i < n; i++){
        water = water + (min(lMax[i], rMax[i]) - heights[i]);
    }

    return water;
}

int main(){

}