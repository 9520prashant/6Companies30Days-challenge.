// 2523. Closest Prime Numbers in Range

class Solution {
public:
    bool isprime(int num){
        if (num <= 1)
            return false;

        for (int i = 2; i <= sqrt(num); i++)
            if (num % i == 0)
                return false;

        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int>temp;
        vector<int>ans(2);
        ans[0] = -1;
        ans[1] = -1;
        int mini = 1e9;
        for(int i=left; i<=right; i++){
            if(isprime(i)){
                temp.push_back(i);
                int size = temp.size();
                if(size < 2)continue;
                
                int diff = temp[size-1] - temp[size-2];
                if(mini > diff){
                    ans[0] = temp[size-2];
                    ans[1] = temp[size-1];
                    mini = diff;
                }
            }
        }
        return ans;
    }
};