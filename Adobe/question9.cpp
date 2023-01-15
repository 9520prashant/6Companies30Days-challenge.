// 433. Minimum Genetic Mutation

class Solution {
public:
    bool changable(string a, string b){
        bool temp=0;
        for(int i=0;i<8;i++){
            if(a[i]!=b[i]){
                if(temp){
                    return 0;
                }
                temp=1;
            }
        }
        return temp;
    }

    int minMutation(string start, string end, vector<string>& bank) {
        queue<pair<int,string>> check;
        check.push(make_pair(0,start));
        int len=bank.size();
        while(!check.empty()){
            pair<int,string> temp=check.front();
            string str=temp.second;
            if(str==end){
                return temp.first;
            }
            check.pop();
            int changelen=0;
            for(int i=0;i<len;i++){
                if(changable(str,bank[i])){
                    check.push(make_pair(temp.first+1,bank[i]));
                    bank.erase(bank.begin()+i);
                    i--;
                    len--;
                }
            }
        }
        return -1;
    }
};