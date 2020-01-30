void Merge(vector<int>& a, int low, int mid, int high){
	int p1 = low, p2 = mid + 1,i=0;
	vector<int> tmp(high-low+1,0);
	while (p1 < mid + 1 && p2 <= high){
		tmp[i++] = a[p1] <= a[p2] ? a[p1++] : a[p2++];
	}
	while (p1 <= mid) {
		tmp[i++] = a[p1++];
	}
	while (p2 <= high) {
		tmp[i++] = a[p2++];
	}
	for (i = 0; i <tmp.size(); i++){
		a[low+i] = tmp[i];
	}
}

void mergesort(vector<int> &a,int low,int high){
	if (low == high){
		return;
	}
	int mid = low + (high - low) / 2;
	mergesort(a, low, mid);
	mergesort(a, mid + 1, high);
	Merge(a, low, mid, high);
}

void merge_sort(vector<int> a){
	int low = 0, high = a.size()-1;
	mergesort(a, low, high);
}
