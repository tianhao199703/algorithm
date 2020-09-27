void bubble_sort(vector<int> &a){
	int n = a.size();
	bool neverSwap = true;
	for (int i = 0; i < n; i++){
		for (int j = n-1; j >= i+1;j--){
			if (a[j] < a[j - 1]){
				neverSwap = false;
				swap(a[j], a[j - 1]);
			}
			if(neverSwap) return;
			neverSwap = true;
		}
	}
}
