// Leetcode-396. Rotate Function
// T.C->O(N) and S.C->O(1)

// ******NOTE*******
// eg- A = [4, 3, 2, 6]

// F(0) = 0A + 1B + 2C +3D
// F(1) = 0D + 1A + 2B +3C
// F(2) = 0C + 1D + 2A +3B
// F(3) = 0B + 1C + 2D +3A

// sum = 1A + 1B + 1C + 1D

// F(1)-F(0) = a+b+c-3d
// = a+b+c+d - 4d
// = sum - n * Bk[0];
// F(1) = F(0) + sum - n*Bk[0]
// (where B[0] is the first element when array is rotated k-times).

// Similarly,
// F(1) = F(0) + sum - 4D
// F(2) = F(1) + sum - 4C
// F(3) = F(2) + sum - 4B

// So,
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum+= nums[i];
        }
        
        int initialState = 0;
        for(int i=0; i<n; ++i) 
           initialState += i*nums[i];
        
        int ans = initialState;
        for(int i=n-1; i>0; --i){
            initialState += (sum - (n*nums[i]));
            ans = max(ans, initialState);
        }
        return ans;
    }
};