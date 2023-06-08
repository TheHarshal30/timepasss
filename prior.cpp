#include<bits/stdc++.h>
using namespace std;

class PriorityQueue{
    vector<int> heap;
    void heapup(int index){
        if(index == 0) return;
        int parent = (index-1)/2;
        if(heap[index] < heap[parent]) {
            swap(heap[index], heap[parent]);
            heapup(parent);
        }
    }
    void heapdown(int i){
        int left = 2*i+1;
        int right = 2*i+2;
        int smallest = i;

        if(left<heap.size() and heap[left] < heap[smallest]){
            smallest  = left;
        }
        if(right<heap.size() and heap[right] < heap[smallest]){
            smallest = right;
        }
        if(smallest != i){
            swap(heap[i], heap[smallest]);
            heapdown(smallest);
        }
    }

    public:
    bool isEmpty(){
        return heap.empty();
    }

    int top(){
        if(isEmpty()) throw runtime_error("Heap is empty");
        return heap[0];
    }
    void push(int key){
        heap.push_back(key);
        heapup(heap.size()-1);
    }
    int pop(){
        if(isEmpty()) throw runtime_error("Heap is empty");
        swap(heap[0], heap[heap.size()-1]);
        heap.pop_back();
        heapdown(0);
    }
};

int main(){
     PriorityQueue pq;
    
    pq.push(5);
    pq.push(3);
    pq.push(8);
    pq.push(2);

    while (!pq.isEmpty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}