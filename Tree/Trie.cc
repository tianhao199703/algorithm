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
