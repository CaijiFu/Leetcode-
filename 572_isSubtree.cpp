class Solution {
public:
    bool isSametree(TreeNode* s, TreeNode* t){
        if(s==NULL&&t==NULL) return true;
        if(s&&t&&s->val==t->val)
            if(isSametree(s->left,t->left))
                if(isSametree(s->right,t->right))
                    return true;
        return false;   
    }//判断两棵树s和t是否相等
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s==NULL) return false;
        return isSametree(s,t)||isSubtree(s->left,t)||isSubtree(s->right,t);

    }
};