struct TreeNode {
    int data;
    struct TreeNode* left;
    stuct TreeNode* right;
};
void Overlap(struct TreeNode* root1, sturct TreeNode* root2)
{
    if(root2==NULL)
        return;
    root1->data=root2->data;
    if(root1->left==NULL) {
        root1->left=root2->left;
    }
    else {
        Overlap(root1->left,root2->left);
    }
    if(root1->right==NULL) {
        root1->right=root2->right;
    }
    else {
        Overlap(root1->right,root2->right);
    }
}
struct TreeNode* OverlapTrees(struct TreeNode* root1, struct TreeNode* root2) 
{
    if(root2==NULL)
        return root1;
    Overlap(root1,root2)
    return root1;
}
