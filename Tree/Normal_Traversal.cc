//Inorder
void inorder_recursion(TreeNode *root){
	if (!root) return;
	inorder_reverse(root->left);
	cout<<root->val;
	inorder_reverse(root->right);
}
void inorder_iteration(TreeNode *root){
	stack<TreeNode*> tmp;
	TreeNode *cur = root;
	while (!tmp.empty() || cur){
		while (cur){
			tmp.push(cur);
			cur = cur->left;
		}
		TreeNode *node = tmp.top();
		tmp.pop();
		cout << node->val;
		cur = node->right;
	}
}
//Preorder
void preorder_recursion(TreeNode *root){
	if (!root) return;
	cout << root->val;
	preorder_recursion(root->left);
	preorder_recursion(root->right);
}
void preorder_iteration(TreeNode *root){
	stack<TreeNode*> tmp;
	TreeNode *cur;
	tmp.push(root);
	while (!tmp.empty()){
		cur = tmp.top();
		tmp.pop();
		cout << cur->val;
		if (cur->right) tmp.push(cur->right);
		if (cur->left) tmp.push(cur->left);
	}
}
//Postorder
void postorder_recursion(TreeNode *root){
	if (!root) return;
	postorder_recursion(root->left);
	postorder_recursion(root->right);
	cout << root->val;
}

void postorder_iteration(TreeNode *root){
	stack<TreeNode*> tmp;
	TreeNode *cur;
	TreeNode *pre = nullptr;
	tmp.push(root);
	while (!tmp.empty()) {
		cur = tmp.top();
    //当前节点被读的条件：是叶子结点或者上一次读取的为其左右孩子
		if ((!cur->left && !cur->right) || (pre && (pre == cur->left || pre == cur->right))){
			cout<<cur->val;
			tmp.pop();
			pre = cur;
		}
		else{
			if (cur->right) tmp.push(cur->right);
			if (cur->left) tmp.push(cur->left);
		}
	}
}
