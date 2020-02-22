class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
//DFS
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) {return nullptr;}
        if (copies.find(node) == copies.end()) {
            copies[node] = new Node(node->val);
            for (Node* neighbor : node->neighbors) {
                copies[node]->neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return copies[node]; 
    }
private:
    unordered_map<Node*,Node*> copies;
};
//BFS
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) {return nullptr;}
        queue<Node*> helper;
        helper.push(node);
        while(!helper.empty()){
            auto curnode = helper.front();
            helper.pop();
            if(copies.find(curnode)==copies.end())  copies[curnode] = new Node(curnode->val);
            for(auto neighbor:curnode->neighbors){
                if(copies.find(neighbor)==copies.end()){
                    helper.push(neighbor);
                    copies[neighbor] = new Node(neighbor->val);
                }
                copies[curnode]->neighbors.push_back(copies[neighbor]);
            }
        }
        return copies[node];
    }
private:
    unordered_map<Node*,Node*> copies;
};
