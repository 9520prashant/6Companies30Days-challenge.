// 166. Fraction to Recurring Decimal
// T.C->O(N)  where N is number of time in which loop exectue
// S.C->O(N) where N is Number of element stored in map
class Solution {
public:
    string fractionToDecimal(int n, int d) {
        if(n==0)    return "0";
        if(d==1)    return to_string(n); // return only n kyu ki divide karne ka kya fayda
        if(d==-1)    return to_string((long)fabs(n)); // return absoulute value in long 
        string ans="";
        if((n<0 && d>0) || (n>0 && d<0))    ans += "-"; // agar koi bhi negetive hoga to - sign add karna hoga na bhai
        n = abs(n);
        d = abs(d);
        ans += to_string(n/d); // chalo kaam start ab n/d karke string me daalo
        long long rem = n%d; // agar reminder hai to usko rem me daalo
        if(!rem)    return ans; // agar reminder nahi hai to ans return kardo aage ka kaam karke kya faayda
        else    ans += "."; // else ans me . add karo fata fat
        unordered_map<int,int>num; // map bana lo taaki ham rem ke corresponding ans ka size() store karge
        while(rem!=0) // jab tk kaam khtm ni hota karte jaao karte jaao
        {
            if(num.find(rem)!=num.end()) // agar map me rem  hai to phle ( daalo fir rem fir ) and return kardo
            {
                // is position par (  ye daalna hai (num[rem])<- represent karega konsi position hgi vo
                ans.insert(num[rem],"(");
                // uske baad end me ) daaalo or return kardo
                ans += ")";
                return ans;
            }
            // yaha num me rem->ans.size()  store hoga
            num[rem] = ans.length();
            // yaha pe next digit banane ke liye 10 se multiple
            rem *= 10;
            // next digit  ko store karlo
            ans += to_string(rem/d);
            // reminder ko d se mod karlo 
            rem %= d;
        }
        return ans;
    
    }
};