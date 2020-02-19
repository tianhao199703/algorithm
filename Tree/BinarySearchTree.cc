struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode *parent;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr), parent(nullptr){}
};

class BST{
public:
	BST() = default;

	TreeNode* Search(TreeNode *root, int k){
		while (root){
			if (root->val == k) return root;
			else{
				if (root->val > k) root = root->left;
				else root = root->right;
			}
		}
		return nullptr;
		
	}
	TreeNode* Maximum(TreeNode *root){
		while (root->right){
			root = root->right;
		}
		return root;
	}
	TreeNode* Minimum(TreeNode *root){
		while (root->left){
			root = root->left;
		}
		return root;
	}
	void Insert(TreeNode *root, TreeNode *node){
		TreeNode *y = nullptr;
		while (root){
			y = root;
			if (node->val < root->val) root = root->left;
			else root = root->right;
		}
		node->parent = y;
		if (y == nullptr) root = node;
		else{
			if (node->val < y->val) y->left = node;
			else y->right = node;
		}
	}
	void Delete(TreeNode *root, TreeNode *node){
		if (node->left == nullptr) transplant(root, node, node->right);
		else{
			if (node->right == nullptr) transplant(root, node, node->left);
			else{
				auto y = Minimum(node->right);
				if (y->parent != node){
					transplant(root, y, y->right);
					y->right = node->right;
					y->right->parent = y;
				}
				transplant(root, node, y);
				y->left = node->left;
				y->left->parent = y;
			}
		}
	}
private:
	void transplant(TreeNode *root, TreeNode *u, TreeNode *v){
		if (u->parent == nullptr) root = v;
		else{
			if (u == u->parent->left) u->parent->left = v;
			else u->parent->right = v;
		}
		if (v != nullptr) v->parent = u->parent;
	}
};
