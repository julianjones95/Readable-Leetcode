#include <vector>

using namespace std;

// Leetcode # 102

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:

    void getNodesInAllLevels(TreeNode* root, int currentLevel, vector<vector<int>> &output) {
        if(root == nullptr) {
            return;
        }
        
        if(currentLevel == output.size()) {
            output.push_back({});
        }
        output[currentLevel].push_back(root->val);

        currentLevel++;
        getNodesInAllLevels(root->left,currentLevel,output);
        getNodesInAllLevels(root->right,currentLevel,output);
        currentLevel--;
        return;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> output = {};

        getNodesInAllLevels(root, 0, output);
        return output;
    }
};
