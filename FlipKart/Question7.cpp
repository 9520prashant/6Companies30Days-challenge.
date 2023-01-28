// 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mat(n, vector<int>(n, 1e9));
        for(auto e : edges) mat[e[0]][e[1]] = mat[e[1]][e[0]] = e[2];
        for(int i=0; i<n; i++) mat[i][i] = 0;
        
        for(int via=0; via<n; via++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    mat[i][j] = min(mat[i][j], mat[i][via] + mat[via][j]);
                }
            }
        }
        int mx = INT_MAX, ans;
        for(int i=0; i<n; i++) {
            int cnt = 0;
            for(int j : mat[i]) {
                if(j <= distanceThreshold) cnt++;
            }
            if(cnt <= mx) ans = i, mx = cnt;   
        }
        return ans;
    }
};