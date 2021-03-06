struct Interval{
	int low;
	int high;
	int Max;
	bool color;//true is red, false is black
	Interval *left;
	Interval *right;
	Interval *parent;
	Interval(int x,int y) : low(x), high(y), Max(y),color(true), left(nullptr), right(nullptr),parent(nullptr){}
};

class IVT{
public:
	IVT(){
		nil = new Interval(0,0);
		nil->parent = new Interval(0,0);
		nil->parent->left = nil;
		nil->color = false;
		root = nil;
	};

	Interval* getroot(){
		return this->root;
	}

	Interval* Search(Interval *i){
		auto x = this->root;
		while (x != this->nil && (i->high < x->low || i->low > x->high)){
			if (x->left != this->nil && x->left->Max >= i->low){
				x = x->left;
			}
			else{ x = x->right; }
		}
		return x;

	}
	Interval* Maximum(Interval *x){
		while (x->right != this->nil){
			x = x->right;
		}
		return x;
	}
	Interval* Minimum(Interval *x){
		while (x->left != this->nil){
			x = x->left;
		}
		return x;
	}

	void Insert(Interval *node){
		Interval *y = this->nil;
		Interval *x = this->root;
		while (x != this->nil){
			//maintain Max
			x->Max = max(x->Max, node->Max);
			y = x;
			if (node->low < x->low) x = x->left;
			else x = x->right;
		}
		node->parent = y;
		if (y == this->nil){
			this->root = node;
			this->root->Max = node->high;
		}
		else{
			if (node->low < y->low) y->left = node;
			else y->right = node;
		}
		node->left = this->nil;
		node->right = this->nil;
		node->color = true;
		insert_fixup(node);
	}

	void Delete(Interval *node){
		auto y = node;
		bool y_ori_color = y->color;
		Interval *x;
		auto g = y->parent;
		//maintain Max
		g->Max = g->high;
		g = g->parent;
		while (g->Max == y->Max)
		{
			g->Max = max(max(g->Max, g->left->Max), g->right->Max);
			g = g->parent;
		}

		if (node->left == this->nil){
			x = node->right;
			transplant(node, node->right);
		}
		else{
			if (node->right == this->nil){
				x = node->left;
				transplant(node, node->left);
			}
			else{
				y = Minimum(node->right);
				y_ori_color = y->color;
				x = y->right;
				if (y->parent == node){
					x->parent = y;
				}
				else{
					transplant(y, y->right);
					y->right = node->right;
					y->right->parent = y;
				}
				transplant(node, y);
				y->left = node->left;
				y->left->parent = y;
				y->color = node->color;
			}
		}
		if (!y_ori_color){
			delete_fixup(root, x);
		}
	}

	void transplant(Interval *u, Interval *v){
		if (u->parent == this->nil) this->root = v;
		else{
			if (u == u->parent->left) u->parent->left = v;
			else u->parent->right = v;
		}
		v->parent = u->parent;
	}

	void insert_fixup(Interval *z){
		while (z->parent->color){
			if (z->parent == z->parent->parent->left){
				auto y = z->parent->parent->right;
				if (y->color){
					z->parent->color = false;
					y->color = false;
					z->parent->parent->color = true;
					z = z->parent->parent;
				}
				else{
					if (z == z->parent->right){
						z = z->parent;
						left_rotate(z);
					}
					z->parent->color = false;
					z->parent->parent->color = true;
					right_rotate(z->parent->parent);
				}
			}
			else{
				auto y = z->parent->parent->left;
				if (y->color){
					z->parent->color = false;
					y->color = false;
					z->parent->parent->color = true;
					z = z->parent->parent;
				}
				else{
					if (z == z->parent->left){
						z = z->parent;
						right_rotate(z);
					}
					z->parent->color = false;
					z->parent->parent->color = true;
					left_rotate(z->parent->parent);
				}
			}
		}
		root->color = false;
	}

	void delete_fixup(Interval *root, Interval *x){
		while (x != this->root && !x->color){
			if (x == x->parent->left){
				auto w = x->parent->right;
				if (w->color){
					w->color = false;
					x->parent->color = true;
					left_rotate(x->parent);
					w = x->parent->right;
				}
				if (!w->left->color && w->right->color){
					w->color = true;
					x = x->parent;
				}
				else{
					if (!w->right->color){
						w->left->color = false;
						w->color = true;
						right_rotate(w);
						w = x->parent->right;
					}
					w->color = x->parent->color;
					x->parent->color = false;
					w->right->color = false;
					left_rotate(x->parent);
					x = this->root;
				}
			}
			else{
				auto w = x->parent->left;
				if (w->color){
					w->color = false;
					x->parent->color = true;
					right_rotate(x->parent);
					w = x->parent->left;
				}
				if (!w->left->color && w->right->color){
					w->color = true;
					x = x->parent;
				}
				else{
					if (!w->left->color){
						w->right->color = false;
						w->color = true;
						left_rotate(w);
						w = x->parent->left;
					}
					w->color = x->parent->color;
					x->parent->color = false;
					w->left->color = false;
					right_rotate(x->parent);
					x = this->root;
				}
			}
		}
		x->color = false;
	}

	void left_rotate(Interval *x){
		auto y = x->right;
		x->right = y->left;
		if (y->left) y->left->parent = x;
		y->parent = x->parent;
		if (x->parent == this->nil) this->root = y;
		else{
			if (x == x->parent->left) y->parent->left = y;
			else y->parent->right = y;
		}
		y->left = x;
		x->parent = y;
		//maintain x
		y->Max = x->Max;
		x->Max = max(max(x->high, x->left->Max), x->right->Max);
	}

	void right_rotate(Interval *y){
		auto x = y->left;
		y->left = x->right;
		if (x->right) x->right->parent = y;
		x->parent = y->parent;
		if (y->parent == this->nil) this->root = x;
		else{
			if (y == y->parent->left) x->parent->left = x;
			else x->parent->right = x;
		}
		x->right = y;
		y->parent = x;
		//maintain Max
		y->Max = x->Max;
		x->Max = max(max(x->high, x->left->Max), x->right->Max);
	}
private:
	Interval *nil;
	Interval *root;

};
