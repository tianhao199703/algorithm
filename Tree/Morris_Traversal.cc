//核心思想：存储cur节点的前驱节点x，使得x->right=cur
//Inorder
void inorder(TreeNode *root){
	TreeNode *cur = root;
	while (cur){
		if (!cur->left){
			cout << cur->val;
			cur = cur->right;
		}
		else{
			TreeNode *tmp = cur->left;
			while (tmp->right && tmp->right != cur) tmp = tmp->right;
			if (!tmp->right){
				  tmp->right = cur;
	        cur = cur->left;
	    }
	    else{//不为空说明已经返回到父节点了
	        tmp->right = nullptr;
				  cout << cur->val;
	        cur = cur->right;
	    }
		}
	}
}
//Preorder
void preorder(TreeNode *root){
	TreeNode *cur = root;
	while (cur){
		if (!cur->left){
			cout << cur->val;
			cur = cur->right;
		}
		else{
			TreeNode *tmp = cur->left;
			while (tmp->right && tmp->right != cur) tmp = tmp->right;
			if (!tmp->right){
				cout << cur->val;
				tmp->right = cur;
	            cur = cur->left;
	        }
	        else{
	            tmp->right = nullptr;
				cur = cur->right;
	        }
		}
	}
}
//Postorder
void reverse(TreeNode *from, TreeNode *to){
	if (from == to) return;
	TreeNode *x = from, *y = from->right, *z;
	do{
		z = y->right;
		y->right = x;
		x = y;
		y = z;
	} while (x != to);
}

void printReverse(TreeNode* from, TreeNode *to){
	reverse(from, to);
	TreeNode *cur = to;
	while(1){
		cout << cur->val;
		if (cur == from) break;
		cur = cur->right;
	}
	reverse(to, from);
}

void postorder(TreeNode *root){
	TreeNode *prehead = new TreeNode(0);
	prehead->left = root;
	TreeNode *cur = prehead;
	while (cur){
		if (!cur->left){
			cur = cur->right;
		}
		else{
			TreeNode *tmp = cur->left;
			while (tmp->right && tmp->right != cur) tmp = tmp->right;
			if (!tmp->right){
				tmp->right = cur;
	            cur = cur->left;
	        }
	        else{
				printReverse(cur->left, tmp);
	            tmp->right = nullptr;
				cur = cur->right;
	        }
		}
	}
}
