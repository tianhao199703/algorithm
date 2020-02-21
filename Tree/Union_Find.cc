class UnionFind {
public:
	UnionFind(int N){
		count = N;
		for (int i = 0; i<N; i++){
			id.push_back(i);
			weight.push_back(1);
		}
	}
    int find(int p){
		int root = p;
		while (root != id[root])root = id[root];
		while (p != root){
			int x = p;
			id[x] = root;
			p = id[p];
		}
		return root;
	}

	bool Union(int p, int q){
		int pid = find(p);
		int qid = find(q);
		if (qid == pid) return false;
		if (weight[pid]<weight[qid]){
			id[pid] = qid;
			weight[qid] += weight[pid];
		}
		else{
			id[qid] = pid;
			weight[pid] += weight[qid];
		}
		count--;
		return true;
	}
private:
	vector<int> id, weight;
	int count;
};
