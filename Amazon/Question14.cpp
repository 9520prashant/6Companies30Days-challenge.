// 1503. Last Moment Before All Ants Fall Out of a Plank

class Solution {
public:
     int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxLeft = left.empty() ? 0 : *max_element(left.begin(), left.end());
         int minRight = right.empty() ? n : *min_element(right.begin(), right.end());
        return max(maxLeft, n - minRight);
    }
};