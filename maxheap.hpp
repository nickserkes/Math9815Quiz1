#ifndef MAXHEAP_HPP
#define MAXHEAP_HPP

#include <vector>
#include <stdexcept>

template<typename T>
class MaxHeap {
private:
    std::vector<T> heap;
    
    // returns the parent node index
    int parent(int index) const { return (index - 1) / 2; }
    // returns the left child node index
    int leftChild(int index) const { return 2 * index + 1; }
    // returns the right child node index
    int rightChild(int index) const { return 2 * index + 2; }

public:
    MaxHeap() = default;
    
    void Add(const T& value) {
        //add value to the back of the heap
        heap.push_back(value);
        
        // Bubble up
        int current = heap.size() - 1;
        // if value is greater than parent, keep swapping up until it is not. Or if it reaches the first node position then stop
        while (current > 0 && heap[parent(current)] < heap[current]) {
            std::swap(heap[parent(current)], heap[current]);
            current = parent(current);
        }
    }
    
    T Remove() {
        T result = heap[0];

        // Replace root with last element and bubble down
        heap[0] = heap.back();
        heap.pop_back();
        
        int current = 0;
        while (true) {
            int left = leftChild(current);
            int right = rightChild(current);
            int maxIndex = current;
            
            // compare left with current
            if (left < heap.size() && heap[left] > heap[maxIndex]) { maxIndex = left;}\
            // compare right with current
            if (right < heap.size() && heap[right] > heap[maxIndex]) { maxIndex = right;}
            // if either the left or right is greater than the current than replace it with the that greater or the two child nodes
            if (current != maxIndex) {
                std::swap(heap[current], heap[maxIndex]);
                current = maxIndex;
            } else { // if neither of the child nodes are greater than the current then we can break since everything is good now
                break;
            }
        }
        
        return result;
    }
    
    int size() const {
        return heap.size(); // return the size
    }
};

#endif // MAXHEAP_HPP

