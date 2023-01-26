#include<bits/stdc++.h>
using namespace std;

int firstOccurrence(vector<int> &nums, int start, int end, int target){
    if(start > end){
        return -1;
    }
    else if(start == end){
        return ((nums[start] == target) ? start : -1);
    }
    else{
        while(start < end){
            int mid = (start + end) / 2;
            if(nums[mid] > target){
                firstOccurrence(nums, start, mid - 1, target);
            }
            else if(nums[mid] < target){
                firstOccurrence(nums, mid + 1, end, target);
            }
            else{
                if((mid == 0) || (mid >= 1 && nums[mid - 1] < nums[mid])){
                    return mid;
                }
                return firstOccurrence(nums, start, mid - 1, target);
            }
        }
    }
}

int lastOccurrence(vector<int> &nums, int start, int end, int target){
    if(start > end){
        return -1;
    }
    else if(start == end){
        return ((nums[start] == target) ? start : -1);
    }
    else{
        while(start < end){
            int mid = (start + end) / 2;
            if(nums[mid] > target){
                lastOccurrence(nums, start, mid - 1, target);
            }
            else if(nums[mid] < target){
                lastOccurrence(nums, mid + 1, end, target);
            }
            else{
                if((mid == end) || (mid <= end - 1 && nums[mid + 1] > nums[mid])){
                    return mid;
                }
                return lastOccurrence(nums, mid + 1, end, target);
            }
        }
    }
}

// vector<int> firstAndLastOccurrence(vector<int> & nums, int target){
//     int first = firstOccurrence(nums, 0, nums.size() - 1, target);
//     int last = lastOccurrence(nums, first, nums.size() - 1, target);
//     return {first, last};
// }

// int main(){

// }
// //Iterative Approach
// class Solution {
// public:
//     void lowerBound(vector<int>&nums,int target,vector<int>&ans){
//         int low=0,high=nums.size()-1;
//         while(low<=high){
//             int mid=(low+high)>>1;
//             if(nums[mid]==target){
//                 ans[0]=mid;
//                 // search left side to find the first occurrence
//                 high=mid-1;
//             }
//             else if(nums[mid]<target)   low=mid+1;
//             else high=mid-1;
//         }
//     }
//     void higherBound(vector<int>&nums,int target,vector<int>&ans){
//         int low=0,high=nums.size()-1;
//         while(low<=high){
    //         int mid=(low+high)>>1;
    //         if(nums[mid]==target){
    //             ans[1]=mid;
    //             //search right side to find the last occurrence
    //             low=mid+1;
    //         }
    //         else if(nums[mid]<target)   low=mid+1;
    //         else high=mid-1;
    //     }
    // }
    // vector<int> searchRange(vector<int>& nums, int target) {
    //     vector<int>ans(2,-1);
    //     lowerBound(nums,target,ans);
    //     higherBound(nums,target,ans);
    //     return ans;
    // }
// };