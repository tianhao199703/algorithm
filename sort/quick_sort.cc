int split(vector<int> &a, int low, int high){
	int i = low, x = a[low];
	for (int j = low + 1; j <= high; j++){
		if (a[j] <= x){
			i++;
			if (i != j){
				swap(a[i], a[j]);
			}
		}
	}
	swap(a[low], a[i]);
	return i;
}
void quicksort(vector<int> &a, int  low, int high){
	if (low < high){
		int mid = split(a, low, high);
		quicksort(a, low, mid - 1);
		quicksort(a, mid + 1, high);
	}
}
void quick_sort(vector<int> a){
	int low = 0, high = a.size() - 1;
	quicksort(a, low, high);
}
