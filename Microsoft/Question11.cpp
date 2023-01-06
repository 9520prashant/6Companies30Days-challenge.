// Leetcode- 1976. Number of Ways to Arrive at Destination
#define ll long long
const int mod = 1e9+7;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        //First create an adjacency list
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0; i < roads.size(); i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        //Now to calculate miminum time to reach the destination let create an array and initialize all the positions to LONG_INT
        // except starting index
        vector<ll> time(n,LONG_MAX);
        time[0] = 0;
        //Now to store the number of way to reach the node in min time let create another array named way
        //And initialize all the nodes to zero but the number of way to start from the staring index is 1 so initialize it
        vector<ll> way(n,0);
        way[0] = 1;
        //As usual create an priority queue of pair which stores node and time to reach the current node
        priority_queue <pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>> > pq;//{time,node}
        pq.push({0,0});
        while(!pq.empty()){
            ll currTime = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it: adj[node]){
                int adjNode = it.first;
                ll timeTotravel = it.second;
                // relax adjNode nodes and push in to priority queue
                // adjNode node ways will be updated with current node ways as
                // we find a lesser time for adjNode node
                if(currTime + timeTotravel < time[adjNode]){
                    time[adjNode] = currTime + timeTotravel;
                    pq.push({time[adjNode],adjNode});
                    way[adjNode] = way[node]%mod;
                }
                // if current node time + timeTotravel = adjNode node cost then
                // this is another way to reach the adjNode node with min time
                // so we update adjNode node ways as ways[adjNode] = (ways[node]+way[adjNode])%mod
                else if(currTime + timeTotravel == time[adjNode])
                    way[adjNode] = (way[adjNode]+way[node])%mod;
            }
        }
        return way[n-1];
    }
};
