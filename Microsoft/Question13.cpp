// 1227. Airplane Seat Assignment Probability
// T.C->O(1) and S.C->O(1)
class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
          if(n==1){return (double)1;}
        return (double)1/2;
    }
};