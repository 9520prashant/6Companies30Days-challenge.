// 1095. Find in Mountain Array

class Solution {
public:
    int findInMountainArray(int target, MountainArray &m) {
        int st=0;
        int end=m.length()-1;
        int mid;
        while(end>st){
            mid=st+(end-st)/2;
           
            if(m.get(mid)>m.get(mid+1)){
                end=mid;
            }
            else if(m.get(mid)<m.get(mid+1)){
                st=mid+1;
            }
            

        }
        int std=mid;
        int endd=m.length()-1;
        end=st;
        st=0;
        while(st<=end){
            mid=st+(end-st)/2;
            if(m.get(mid)==target){
                return mid;
            }
            else if(m.get(mid)>target){
                end=mid-1;
            }
            else{
                st=mid+1;
            }
        }
        while(std<=endd){
            mid=std+(endd-std)/2;
            if(m.get(mid)==target){
                return mid;
            }
            else if(m.get(mid)<target){
                endd=mid-1;
            }
            else{
                std=mid+1;
            }
           
        }
        

   return -1; }
};