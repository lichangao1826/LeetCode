/*Given a binary tree

struct TreeLinkNode {
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
Recursive approach is fine, implicit stack space does not count as extra space for this problem.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
Example:

Given the following perfect binary tree,

     1
   /  \
  2    3
 / \  / \
4  5  6  7
After calling your function, the tree should look like:

     1 -> NULL
   /  \
  2 -> 3 -> NULL
 / \  / \
4->5->6->7 -> NULL*/

/*
思路：
队列实现层次遍历，每层结束将最后一个结点的next指针指向NULL
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        queue<TreeLinkNode*> Q;
        Q.push(root);
        while(!Q.empty()) {
            int size = Q.size();
            while(size --){
                TreeLinkNode *node = Q.front();
                Q.pop();
                if(!size){
                    node->next = NULL;
                } else {
                    node->next = Q.front();
                }
                if(node->left) {
                    Q.push(node->left);
                }
                if(node->right) {
                    Q.push(node->right);
                }
            }
        }
    }
};
