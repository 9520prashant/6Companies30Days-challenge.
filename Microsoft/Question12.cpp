// 1392. Longest Happy Prefix
// T.C->O(N) and S.C->O(N)
class Solution {
public:
     string longestPrefix(string s) {
        string ans="";
        vector<int>pos(s.size(), 0);
        int i=0, j=1;
        while(j<s.size()){
            if(s[i]==s[j]){
                pos[j]=i+1;
                i++;
                j++;
            }
            else if(i){
                i=pos[i-1];
            }
            else{
                j++;
            }
        }
        ans=s.substr(0, i);
        return ans;
    }
};
