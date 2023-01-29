// 692. Top K Frequent Words

class Solution {
public:
    struct comp {
        bool operator()(pair<string,int>&a, pair<string,int>&b){
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        }  
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        vector<string>ans;
        for(auto i:words)
            mp[i]++;
        
        priority_queue<pair<string,int>, vector<pair<string,int>>, comp >pq;
        for(auto &it : mp) {
            pq.push({it.first, it.second});
            
            if(pq.size() > k)
                pq.pop();
        }
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
};