/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class BSTIterator {
private:
    stack<TreeNode *> stackTreeNode;

public:
    BSTIterator(TreeNode *root) {
        if(root) pushSubNode(root);
    }

    void pushSubNode(TreeNode *pnode){
        while(pnode){
            stackTreeNode.push(pnode);
            pnode=pnode->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stackTreeNode.empty();
    }

    /** @return the next smallest number */
    int next() {
        int idata=stackTreeNode.top()->val;
        TreeNode *pringht=stackTreeNode.top()->right;
        stackTreeNode.pop();
        if(pringht) pushSubNode(pringht);
        return idata;
    }
};
/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
