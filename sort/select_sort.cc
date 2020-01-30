void select_sort(vector<int> a){
	int n = a.size(),pos;
	for (int i = 0; i < n; i++){
		pos = i;
		for (int j = i; j<n;j++){
			if (a[j] < a[pos]){
				pos = j;
			}
		}
		swap(a[i], a[pos]);
	}
}
