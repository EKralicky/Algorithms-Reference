#include <iostream>
#include <vector>

namespace DataStructures {



/*

--------------------------------------------------------------
Heaps can be implemented with an array

Given a node at index i,

Parent node is at index         - floor(i/2)
Left child node is at index     - 2i
Right child node is at index    - 2i + 1

Leaf nodes are at index floor(n/2) + 1, floor(n/2) + 2 ...
--------------------------------------------------------------
The height of a heap is the height of the root node (lg n)
--------------------------------------------------------------
Max number of elements in a heap of height h?
2^(h+1) - 1
--------------------------------------------------------------

*/


// For a max heap, a nodes children are smaller than the nodes parent
class MaxHeap {

public:
    MaxHeap();
    ~MaxHeap();
private:
    int heap_size = 0;
    std::vector<int> heap_arr;

    inline int get_left(int i) { return 2 * i; }
    inline int get_right(int i) { return (2 * i) + 1; }
    inline int get_parent(int i) { return floor(i/2); }

    void max_heapify(int i);

};

void MaxHeap::max_heapify(int i) {
    int largest = 0;
    int left = get_left(i);
    int right = get_right(i);
    // Compare the values at i, the root of the branch we are trying to fix,
    // and its left child. If the left child is greater than the root, we have a
    // violation and we keep track of the largest value. Tn this case the left.
    // Once we have the greatest value, we can simply swap the root with the greatest
    // value and recurse on the index of the largest we just swapped
    if (left <= heap_size && heap_arr[left] > heap_arr[i]) {
        largest = left;
    } 
    else {
        largest = i;
    }
    if (right <= heap_size && heap_arr[right] > heap_arr[largest]) {
        largest = right;
    }
    // If theres a heap violation... i.e theres a child thats larger than the root
    if (largest != i) { 
        
    }
}
}