// Leetcode- 593. Valid Square
// Complexity : O(n)

class Solution {
public:
    int distance(vector<int>p1, vector<int>p2){
    return (((p2[0] - p1[0]) * (p2[0] - p1[0])) + ((p2[1] - p1[1]) * (p2[1] - p1[1])));
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>>pts = {p1,p2,p3,p4};
        // why set Because it will store unique value 
        set<int>s;
        for(int i=0; i<4; i++){
            for(int j=i+1; j<4; j++){
                int val = distance(pts[i], pts[j]);

                if(val != 0){
                    s.insert(val);
                }else{
                    return false;
                }
            }
        }
        // why? s.size() == 2 Because one value for all the sides of sqaue and another one for diagonal of sqaure 
        return s.size() == 2;
    }
};