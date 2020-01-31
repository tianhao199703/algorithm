int parent(int i){
	return i / 2;
}
int left(int i){
	return 2 * i + 1;
}
int right(int i){
	return 2 * i + 2;
}

void max_heapfy(vector<int> &a, int index,int size){
	int l = left(index), r = right(index),n=a.size(),largest;
	while (l < size) {
		if (a[l] < a[r] && r < size) {
			largest = r;
		}
		else {
			largest = l;
		}
		if (a[index] > a[largest]) {
			largest = index;
		}
		if (index == largest) {
			break;
		}
		swap(a[largest], a[index]);
		index = largest;
		l = left(index);
		r = right(index);
	}
}

void build_max_heap(vector<int> &a){
	for (int i = 0; i < a.size(); i++) {
		int curidx = i;
		int pidx = parent(i);
		while (a[curidx] > a[pidx]) {
			swap(a[curidx], a[pidx]);
			curidx = pidx;
			pidx = parent(curidx);
		}
	}
}

void heap_sort(vector<int> a){
	int n = a.size();
	build_max_heap(a);
	for (int i = n-1; i > 0; i--){
		swap(a[0], a[i]);
		max_heapfy(a, 0, i);
	}
}
