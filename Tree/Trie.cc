class TrieNode{
public:
	bool is_end; // judge whether it's a leaf node or not
	vector<TrieNode*> children;//initialize 26 letter subnode
	TrieNode(){
		is_end = false;
		children = vector<TrieNode*>(26, nullptr);
	}
};

class Trie{
public:
	Trie(vector<string>& words){
		root = new TrieNode();
		for (int i = 0; i<words.size(); ++i)
			addWord(words[i]);
	}
	TrieNode* getRoot(){ return root; }
	void addWord(const string& word){
		TrieNode* cur = root;
		for (int i = 0; i<word.size(); ++i){
			int index = word[i] - 'a';
			if (cur->children[index] == nullptr)
				cur->children[index] = new TrieNode();
			cur = cur->children[index];
		}
		cur->is_end = true;
	}
private:
	TrieNode* root;
};

// java version
class Trie {
    TreeNode root;

    /** Initialize your data structure here. */
    public Trie() {
        this.root = new TreeNode();
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        TreeNode cur = root;
        for(int i=0;i<word.length();i++){
            int index = word.charAt(i) - 'a';
            if(cur.child.get(index) == null){
                cur.child.set(index,new TreeNode());
            }
            cur = cur.child.get(index);
        }
        cur.isLeaf = true;
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        TreeNode cur = root;
        for(int i=0;i<word.length();i++){
            int index = word.charAt(i) - 'a';
            if(cur.child.get(index) == null){
                return false;
            }
            cur = cur.child.get(index);
        }
        return cur.isLeaf;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        TreeNode cur = root;
        for(int i=0;i<prefix.length();i++){
            int index = prefix.charAt(i) - 'a';
            if(cur.child.get(index) == null){
                return false;
            }
            cur = cur.child.get(index);
        }
        return true;
    }
}

class TreeNode{
    boolean isLeaf;
    List<TreeNode> child;

    public TreeNode(){
        isLeaf = false;
        child = new ArrayList(26);
        for(int i=0;i<26;i++){
            child.add(null);
        }
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */
