struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode *parent;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr), parent(nullptr){}
};

class BST{
public:
	BST() { root = nullptr; };

	TreeNode* getroot(){
		return this->root;
	}

	TreeNode* Search(TreeNode *x, int k){
		while (x){
			if (x->val == k) return x;
			else{
				if (x->val > k) x = x->left;
				else x = x->right;
			}
		}
		return nullptr;

	}
	TreeNode* Maximum(TreeNode *x){
		while (x->right){
			x = x->right;
		}
		return x;
	}
	TreeNode* Minimum(TreeNode *x){
		while (x->left){
			x = x->left;
		}
		return x;
	}
	void Insert(TreeNode *node){
		TreeNode *y = nullptr;
		TreeNode *x = this->root;
		while (x){
			y = x;
			if (node->val < x->val) x = x->left;
			else x = x->right;
		}
		node->parent = y;
		if (y == nullptr) this->root = node;
		else{
			if (node->val < y->val) y->left = node;
			else y->right = node;
		}
	}
	void Delete(TreeNode *node){
		if (node->left == nullptr) transplant(node, node->right);
		else{
			if (node->right == nullptr) transplant(node, node->left);
			else{
				auto y = Minimum(node->right);
				if (y->parent != node){
					transplant(y, y->right);
					y->right = node->right;
					y->right->parent = y;
				}
				transplant(node, y);
				y->left = node->left;
				y->left->parent = y;
			}
		}
	}
private:
	void transplant(TreeNode *u, TreeNode *v){
		if (u->parent == nullptr) this->root = v;
		else{
			if (u == u->parent->left) u->parent->left = v;
			else u->parent->right = v;
		}
		if (v != nullptr) v->parent = u->parent;
	}
	TreeNode *root;
};
