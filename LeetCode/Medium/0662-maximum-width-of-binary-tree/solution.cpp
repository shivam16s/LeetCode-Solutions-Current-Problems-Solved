/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void fun(map<int,pair<long long, long long>> &mp, long long no, int lvl){
        if(mp.find(lvl) == mp.end()){
            mp[lvl].first = no;
            mp[lvl].second = no;
        }
        else{
            if(mp[lvl].first > no)mp[lvl].first = no;
            if(mp[lvl].second < no)mp[lvl].second = no;
        }
    }
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,pair<int, long long>>> q;
        map<int,pair<long long,long long>> mp;
        q.push({root,{0,0}});
        while(!q.empty()){
            // auto temp = q.front();
            // q.pop();
            // fun(mp, temp.second.second, temp.second.first);
            // if(temp.first->left)q.push({temp.first->left,{temp.second.first + 1,temp.second.second*2 + 1}});
            // if(temp.first->right)q.push({temp.first->right,{temp.second.first + 1, (temp.second.second*2)+2}});        
            int size = q.size();
            // Capture the index of the very first node on this level
            long long min_index = q.front().second.second; 
            
            for(int i = 0; i < size; i++){
                auto temp = q.front();
                q.pop();
                
                // NORMALIZE the index by subtracting the min_index
                long long cur_id = temp.second.second - min_index;
                
                // Pass the normalized ID to your map
                fun(mp, cur_id, temp.second.first);
                
                // Use the normalized ID to calculate the children's IDs
                if(temp.first->left) {
                    q.push({temp.first->left, {temp.second.first + 1, cur_id * 2 + 1}});
                }
                if(temp.first->right) {
                    q.push({temp.first->right, {temp.second.first + 1, cur_id * 2 + 2}}); 
                }                                            
            }                                     
        }
        long long mx = 0;
        for(auto it : mp){
            mx = max(mx, it.second.second- it.second.first + 1);
        }
        return mx;
    }
};