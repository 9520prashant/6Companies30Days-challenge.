// 337. House Robber III

class Solution {
public:
    // Time complexity - O(N)
    // vector<int> of size = 2 where -> [pick, not pick]
    vector<int> traverser(TreeNode* curr){
        if(!curr){
            return {0, 0};
        }
        
        vector<int>l, r, t;
        l = traverser(curr->left);
        r = traverser(curr->right);
        
        t.push_back( l[1] + r[1] + curr->val );
        t.push_back( max(l[0], l[1]) + max(r[0], r[1]) );
        
        return t;
    }
    int rob(TreeNode* root) {
        vector<int>holder = traverser(root);
        return max(holder[0], holder[1]);
    }
};