#include <vector>

using namespace std;


 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if(pre.empty() || post.empty()){
            return nullptr;
        }
        return helper(pre,post,0,0,post.size() - 1);

    }

    TreeNode* helper(const vector<int>& pre, const vector<int>& post, int p1, int p2,int end){
        if(p1 >= pre.size() || p2 > end){
            return nullptr;
        }
        int i = p2;
        for(;i < end; ++i){
            if(post[i] == pre[p1 + 1]){
                break;
            }
        }
        TreeNode* root = new TreeNode(pre[p1]);
        if(p2 == end){
            return root;
        }
        root->left = helper(pre,post,p1 + 1, p2, i);
        root->right = helper(pre, post, p1 + i - p2 + 2, i + 1, end - 1);
        return root;
    }
};