class KthLargest {
private:
    int k;
    vector<int> heap;

    void heapifyUp(int i) {
        int p = (i - 1) / 2;

        if (heap[p] > heap[i]) {
            swap(heap[p], heap[i]);
            heapifyUp(p);
        }
    }

    void heapifyDown(int i) {
        int n = heap.size();
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int smallest = i;

        if (l < n && heap[l] < heap[smallest]) smallest = l;
        if (r < n && heap[r] < heap[smallest]) smallest = r;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    void popMin() {
        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty()) heapifyDown(0);
    }


public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int x : nums) add(x);
    }
    
    int add(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
        if (heap.size() > k) {
            popMin();
        }
        return heap[0];
    }
};
