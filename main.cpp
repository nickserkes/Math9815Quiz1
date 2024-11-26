#include <vector>
#include <iostream>
#include <functional>
#include "maxheap.hpp"

// Helper function to partition the array
int partitionArray(std::vector<int>& numbers, int startIndex, int endIndex) {
    int pivotValue = numbers[endIndex]; // pivot on the end value
    int smallerElementIndex = startIndex - 1;
    
    // Compare each element with the pivot
    for(int currentIndex = startIndex; currentIndex < endIndex; currentIndex++) {
        // If current element is smaller than pivot, move it to the left side
        if(numbers[currentIndex] <= pivotValue) {
            smallerElementIndex++;
            // Swap elements
            int temp = numbers[smallerElementIndex];
            numbers[smallerElementIndex] = numbers[currentIndex];
            numbers[currentIndex] = temp;
        }
    }
    
    // Put pivot in its correct position
    int temp = numbers[smallerElementIndex + 1];
    numbers[smallerElementIndex + 1] = numbers[endIndex];
    numbers[endIndex] = temp;
    
    return smallerElementIndex + 1;
}

// Function to perform QuickSort (Recursive function)
void quickSort(std::vector<int>& numbers, int startIndex, int endIndex) {
    if(startIndex < endIndex) {
        // Find the partition position
        int partitionPosition = partitionArray(numbers, startIndex, endIndex);
        
        // Sort the left part
        quickSort(numbers, startIndex, partitionPosition - 1);
        // Sort the right part
        quickSort(numbers, partitionPosition + 1, endIndex);
    }
}

void testQuickSort() {
    std::vector<int> numbers;
    srand(static_cast<unsigned int>(time(nullptr))); // Seed random number generator

    // Add 10 random integers to the vector
    for (int i = 0; i < 10; i++) {
        int randomValue = rand() % 100; // Random numbers between 0 and 99
        numbers.push_back(randomValue);
        std::cout << "Added: " << randomValue << std::endl;
    }

    // Sort the vector using QuickSort
    quickSort(numbers, 0, numbers.size() - 1);

    // Print sorted array
    std::cout << "Sorted array: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void testMaxHeap() {
    MaxHeap<int> maxHeap;
    srand(static_cast<unsigned int>(time(nullptr))); // Seed random number generator

    // Add 10 random integers to the max heap
    for (int i = 0; i < 10; i++) {
        int randomValue = rand() % 100; // Random numbers between 0 and 99
        maxHeap.Add(randomValue);
        std::cout << "Added: " << randomValue << std::endl;
    }

    std::cout << "Popping elements from the max heap in descending order:" << std::endl;
    // Pop all elements from the max heap
    while (maxHeap.size() > 0) {
        std::cout << maxHeap.Remove() << " ";
    }
    std::cout << std::endl;
}

int main() {
    /*
    std::vector<int> numbers;
    srand(time(nullptr)); // Seed random number generator
    
    for(int i = 0; i < 10; i++) {
        numbers.push_back(rand() % 100); // Random numbers between 0 and 99
    }
    
    // Sort the vector using QuickSort
    quickSort(numbers, 0, numbers.size() - 1);
    
    // Print sorted array
    std::cout << "Sorted array: ";
    for(int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    */
    std::cout << "Quicksort Test\n";
    testQuickSort();
    std::cout << "\nMaxHeap Test\n";
    testMaxHeap();

    return 0;
}

// NOTE: Cursor Code Editor was used to complete this Quiz.
// This code editor has integrated ai features which helped me write code more quickly an efficiently
// Thus some code was generated through ai, and iterated on by me thereafter