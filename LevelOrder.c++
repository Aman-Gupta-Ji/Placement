struct TreeNode {
    int data;
    struct TreeNode* left;
    stuct TreeNode* right;
};
vector<int> LevelOrder(struct TeeNode* root, int l, int h)
{

    vector<int> res;
    if (root == NULL)
        return res;
 
    // Create an empty queue for level order traversal
    queue<sturct TreeNode*> q;
 
    // Enqueue Root and initialize height
    q.push(root);
 
    while (q.empty() == false) {
        // Print front of queue and remove it from queue
        sturct Treesturct TreeNode* node = q.front();
        // cout << node->data << " ";
        if(node->data>=l&&node->dat<=h)
            res.push_back(node->dat);
        q.pop();
 
        /* Enqueue left child */
        if (node->left != NULL)
            q.push(node->left);
 
        /*Enqueue right child */
        if (node->right != NULL)
            q.push(node->right);
    }
    return res;
}