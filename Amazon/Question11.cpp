// 2400. Number of Ways to Reach a Position After Exactly k Steps

class Solution {
public:
    const int mod = 1000000007;
    
    //Function to calculate nCr 
	//C(n, r) = C(n-1, r-1) + C(n-1, r)
    int nCr(int n, int r){
        if(r == 0) return 1;
        vector<int> v(r+1,0);
        v[0] = 1;
        for(int i=1; i<=n; i++){
            for(int j=r; j>0; j--)
                v[j] = ((v[j] % mod) + (v[j-1] % mod)) % mod;
        }
        return v[r];
    }    
    
   int numberOfWays(int startPos, int endPos, int k) {
        int diff = abs(endPos - startPos);
        //difference is greater than k or 
        //after moving diff steps, we have odd number of steps left
        if(diff > k or diff + k & 1) return 0;
        
        long r = (diff + k) / 2;
        return nCr(k,r);
    }
};