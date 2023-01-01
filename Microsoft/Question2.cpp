// Leetcode-216. Combination Sum III
// T.C->O(2^N) and S.C->O(N) Where N are number from 1-9
class Solution {
public:
    void helper(int start, int k, int n, vector<int>&temp, vector<vector<int>>&ans){
        if(k == 0){
            if(n == 0){
                ans.push_back(temp);
            }
            return;
        }
        if(start > 9)return ;
        temp.push_back(start);
        helper(start+1, k-1, n - start, temp, ans);
        temp.pop_back();
        helper(start+1, k, n, temp, ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        vector<vector<int>>ans;
        helper(1, k, n, temp, ans);
        return ans;
    }
};