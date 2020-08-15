void max_heapfy(vector<int> &a, int i,int size){
	int l = i * 2 + 1, r = i * 2 + 2, largest = i;
        if (l < heapSize && a[l] > a[largest]) {
            largest = l;
        } 
        if (r < heapSize && a[r] > a[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap(a[i], a[largest]);
            maxHeapify(a, largest, heapSize);
        }
}

void build_max_heap(vector<int> &a, int heapSize){
	for (int i = heapSize / 2; i >= 0; --i) {
            maxHeapify(a, i, heapSize);
        }
}

void heap_sort(vector<int> a){
	int n = a.size();
	build_max_heap(a, n);
	for (int i = nums.size() - 1; i > 0; --i) {
            swap(nums[0], nums[i]);
            --heapSize;
            maxHeapify(nums, 0, heapSize);
        }
}
