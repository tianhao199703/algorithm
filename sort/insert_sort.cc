void insert_sort(vector<int> a){
	int n = a.size(),x,j;
	for (int i = 1; i < n; i++){
		x = a[i];
		j = i - 1;
		while (j>=0 && a[j] > x){
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
