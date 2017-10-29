/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode *n, vector<double> &levelSum, vector<int> &levelCount, int level)
    {
        if(!n)
            return;
        if(levelSum.size() <= level)
            levelSum.push_back(n->val);
        else
            levelSum[level] += n->val;
        if(levelCount.size() <= level)
            levelCount.push_back(1);
        else
            levelCount[level]++;
        helper(n->left, levelSum, levelCount, level+1);
        helper(n->right, levelSum, levelCount, level+1);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> levelSum;
        if(!root)
            return levelSum;
        vector<int> levelCount;
        helper(root, levelSum, levelCount, 0);
        for(int i=0; i < levelSum.size(); i++)
            levelSum[i] = levelSum[i]/(double)levelCount[i];
        return levelSum;
        
    }
};
