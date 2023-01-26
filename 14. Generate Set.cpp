#include<bits/stdc++.h>
using namespace std;

void generateSet(vector<vector<int>> &result, vector<int> &setSoFar, const vector<int> &nums, int index){
    if(index >= nums.size()){
        result.push_back(setSoFar);
    }
    else{
        //recursion
        setSoFar.push_back(nums[index]);
        generateSet(result, setSoFar, nums, index + 1);

        //backtracking
        setSoFar.pop_back();
        generateSet(result, setSoFar, nums, index + 1);
    }
}
vector<vector<int>> subsets(vector<int>& nums) {
    if(nums.size() == 0){
        return {};
    }
    vector<vector<int>> result;
    vector<int> setSoFar;

    generateSet(result, setSoFar, nums, 0);
    return result;
}

int main(){
    
}