// 334. Increasing Triplet Subsequence

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)return false;

        // O(n^3)
        // for(int i=0; i<n; i++){
        //     for(int j=i+1; j<n; j++){
        //         for(int k=j+1; k<n; k++){
        //             if(nums[i] < nums[j] && nums[j] < nums[k] && nums[i] < nums[k]){
        //                 return true;
        //             }
        //         }
        //     }
        // }

        // O(n)
        int left = INT_MAX;
        int mid = INT_MAX;
        for(int i=0; i<n; i++){
            if(nums[i]  > mid){
                return true;
            }else if (nums[i] > left && nums[i] < mid){
                mid = nums[i];
            }else if(nums[i] < left){
                left = nums[i];
            }
        }
        return false;;
    }
};