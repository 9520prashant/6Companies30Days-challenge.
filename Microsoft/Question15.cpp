// 1358. Number of Substrings Containing All Three Characters
// T.C->O(n) and S.C->O(1)
class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt=0, j=0;
        vector<int>v(3, 0);
        for(int i=0; i<s.size(); i++){
            v[s[i]-'a']++;
            while(v[0] && v[1] && v[2]){
                cnt+=s.size()-i;
                v[s[j]-'a']--;
                j++;
            }
        }
        return cnt;
    }
};