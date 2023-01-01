// Leetcode-299. Bulls and Cows
T.C->O(N) and S.C->O(N)class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int>mp;
        int bull = 0;
        int cow = 0;
        string ans;
        for(int i=0; i<secret.size(); i++){
            if(secret[i] == guess[i]){
                bull++;   
            }else{
                mp[secret[i]]++;
            }
        }
        for(int i=0; i<secret.size(); i++){
            if(secret[i] != guess[i]){
                if(mp[guess[i]] > 0){
                    cow ++;
                    mp[guess[i]]--;
                }
            }
        }
        ans = to_string(bull) + "A" + to_string(cow) + "B";
        return ans;
    }
};