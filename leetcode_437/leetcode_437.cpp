#include <iostream>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    int dfs(TreeNode* root, int sum){ 
        if(root == nullptr){
            return 0;
        }
        int count = 0;
        if(root->val == sum){
            ++count;
        }
        count += dfs(root->left, sum - root->val);
        count += dfs(root->right, sum- root->val);
        return count;

    } 
    int pathSum(TreeNode* root, int sum) {
        if(root == nullptr){
            return 0;
        }
        return dfs(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};