// 1947. Maximum Compatibility Score Sum

int dp[300];      //dp-array
class Solution {
public:
    int solve(vector<int> &a, vector<int> &b, int i, int mask, int n, int m){
        if(i>=n){
            return 0;
        }
        if(dp[mask]!=-1){
            return dp[mask];
        }
        int ans=0;
        for(int k=0; k<n; k++){    //for each mentor
            if((mask&(1<<k))){                     //check if mentor has not chosen yet
                int new_mask=mask^(1<<k);
                
                int current_ans=0;
                for(int x=0; x<m; x++){
                    if((a[i]&(1<<x)) == (b[k]&(1<<x))){      //if xth bit of student and mentor is same, increase the answer
                        current_ans++;
                    }
                }
                ans=max(ans, current_ans + solve(a, b, i+1, new_mask, n, m) );
            }
        }
        return dp[mask]=ans;
    }
    
    int maxCompatibilitySum(vector<vector<int>>& s, vector<vector<int>>& mr){
        int n = s.size();
        int m = s[0].size();
        vector<int> a, b;
        //convert to decimal e.g. [1,1,0] = 6
        for(auto v: s){                                //for students array
            int x=0;
            for(int i=0; i<m; i++){
                x+=(v[i]<<((m-i)-1));
            }
            a.push_back(x);
        }
        
        for(auto v: mr){                               //for mentor array
            int x=0;
            for(int i=0; i<m; i++){
                x+=(v[i]<<((m-i)-1));
            }
            b.push_back(x);
        }
        
        int mask = pow(2, n)-1;                          //all set bit   1 -> mentor not chosen, 0 -> mentor chosen
        //initialise dp array with -1
        for(int j=0; j<=mask; j++){
            dp[j]=-1;
        }
        
        return solve(a, b, 0, mask, n, m);
    }
};