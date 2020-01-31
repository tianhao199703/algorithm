void counting_sort(vector<int> a){
	auto max = max_element(a.begin(), a.end());
	auto min = min_element(a.begin(), a.end());
	int k = *max-*min+1, n = a.size();
	vector<int> count(k, 0),newa(a);
	for (int i = 0; i < n; i++){
		count[a[i]-*min]++;
	}
	for (int i = 1; i < k; i++){
		count[i] += count[i - 1];
	}
	for (int i = n - 1; i >= 0; i--){
		newa[count[a[i]-*min]-1] = a[i];
		count[a[i]-*min]--;
	}
}
