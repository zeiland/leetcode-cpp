#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret;
        doPreTrans(root, ret);
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> pre;
        trans2vec(data, pre);
        int i = 0;
        return buildTree(pre, i);
    }

private:
    void doPreTrans(TreeNode* root, string& res){
        if(root == nullptr){
            res += "-1123|";
            return;
        }
        res += to_string(root->val) + "|";
        doPreTrans(root->left, res);
        doPreTrans(root->right, res);
    }
    void trans2vec(const string& data, vector<int>& pre){
        int begin = 0;
        int end = 0;
        while(begin != data.size()){
            while(data[end] != '|'){
                ++end;
            }
            pre.push_back(stoi(data.substr(begin,end - begin)));
            begin = ++end;
        }
    }
    TreeNode* buildTree(const vector<int>& pre, int& i){
        if(pre[i] == -1123){
            ++i;
            return nullptr;
        }
        TreeNode* node = new TreeNode(pre[i]);
        ++i;
        node->left = buildTree(pre, i);
        node->right = buildTree(pre, i);
        return node;
    }
};


// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));