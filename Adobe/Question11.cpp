// 2034. Stock Price Fluctuation 
class StockPrice {
public:
    map<int,int> mp;
    multiset<int> mset;
    //priority_queue<int> maxheap;
    //priority_queue<int,vector<int>,greater<int>> minheap;
    int time=0; int curr=0;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if (timestamp>=time){curr= price; time=timestamp;}
        if (mp.find(timestamp)== mp.end()){
            mp.insert({timestamp,price});
            mset.insert(price);
        }
        else{
            auto it= mset.find(mp[timestamp]);
            mset.erase(it);
            mp[timestamp]= price;
            mset.insert(price);
        }

    }
    
    int current() {
        return curr;
    }
    
    int maximum() {
        //return maxheap.top();
        return *(mset.rbegin());
    }
    
    int minimum() {
        //return minheap.top();
        return *(mset.begin());
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */