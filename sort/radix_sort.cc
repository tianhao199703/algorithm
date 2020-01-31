int maxbit(vector<int> a){
	int len = 0;
	for (auto x : a){
		int count = 0;
		while (x>0){
			x /= 10;
			count++;
		}
		len = max(len, count);
	}
	return len;
}

void radix_sort(vector<int> a){
	const int buckets_number = 10;
	vector<vector<int> > buckets(10);
	int len = maxbit(a);
	int r = 1;
	for (int i = 0; i<len; i++){
		for (int x : a){
			int tmp = x / r;
			int index = tmp%buckets_number;
			buckets[index].push_back(x);
		}
		int j = 0;
		for (int i = 0; i < buckets.size();i++){
			for (int x : buckets[i]){
				a[j] = x;
				j++;
			}
			buckets[i].clear();
		}
		r = r * 10;
	}
}
