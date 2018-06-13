/*Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

Note: A leaf is a node with no children.

Example:

Input: [1,2,3]
    1
   / \
  2   3
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.
Example 2:

Input: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.*/

/*
思路：
递归，从根结点向下遍历，遇到叶子结点则加到res上
*/

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
private:
    int res = 0;
public:
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        SiftDown(root, 0);
        return res;
    }
    void SiftDown(TreeNode* node, int current_value) {
        if(!node->left && !node->right)
            res += current_value * 10 + node->val;
        if(node->left) {
            SiftDown(node->left, current_value * 10 + node->val);
        }
        if(node->right) {
            SiftDown(node->right, current_value * 10 + node->val);
        }
    }
};
