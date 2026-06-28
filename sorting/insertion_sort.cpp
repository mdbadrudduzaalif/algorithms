/**
 * @file insertion_sort.cpp
 * @brief Implementation of the Insertion Sort algorithm in C++.
 * 
 * Insertion Sort is a simple comparison-based sorting algorithm. It builds the final sorted array
 * one item at a time. It is much less efficient on large lists than more advanced algorithms such
 * as Quick Sort, Merge Sort, or Heap Sort, but it has several advantages:
 *   - Simple implementation
 *   - Highly efficient for small datasets
 *   - Adaptive: efficient for datasets that are already substantially sorted (O(N) best case)
 *   - Stable: does not change the relative order of elements with equal keys
 * 
 * Time Complexity:
 *   - Best Case: O(N) - The input array is already sorted.
 *   - Average Case: O(N^2)
 *   - Worst Case: O(N^2) - The input array is sorted in reverse order.
 * 
 * Space Complexity:
 *   - O(1) - In-place sorting, no extra memory is allocated.
 */

#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <algorithm>

/**
 * @brief Sorts a vector of elements in ascending order using Insertion Sort.
 * 
 * @tparam T The data type of the elements in the vector (must support comparison operators).
 * @param arr The input vector to be sorted.
 */
template <typename T>
void insertionSort(std::vector<T>& arr) {
    if (arr.size() <= 1) {
        return;
    }

    size_t n = arr.size();
    for (size_t i = 1; i < n; ++i) {
        T key = arr[i];
        int j = static_cast<int>(i) - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    std::cout << "Running Insertion Sort Verification Tests..." << std::endl;

    // Test Case 1: Standard Unsorted Integer Vector
    std::vector<int> intVec = {12, 11, 13, 5, 6};
    std::vector<int> expectedIntVec = {5, 6, 11, 12, 13};
    insertionSort(intVec);
    assert(intVec == expectedIntVec);
    std::cout << "Test Case 1 Passed (Standard unsorted integer array)." << std::endl;

    // Test Case 2: Already Sorted Vector (Verifying adaptive O(N) case)
    std::vector<int> sortedVec = {1, 2, 3, 4, 5};
    std::vector<int> expectedSortedVec = {1, 2, 3, 4, 5};
    insertionSort(sortedVec);
    assert(sortedVec == expectedSortedVec);
    std::cout << "Test Case 2 Passed (Already sorted array)." << std::endl;

    // Test Case 3: Reverse Sorted Vector (Worst Case)
    std::vector<int> revVec = {5, 4, 3, 2, 1};
    std::vector<int> expectedRevVec = {1, 2, 3, 4, 5};
    insertionSort(revVec);
    assert(revVec == expectedRevVec);
    std::cout << "Test Case 3 Passed (Reverse sorted array)." << std::endl;

    // Test Case 4: Vector with Duplicate Elements
    std::vector<int> dupVec = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    std::vector<int> expectedDupVec = {1, 1, 2, 3, 3, 4, 5, 5, 6, 9};
    insertionSort(dupVec);
    assert(dupVec == expectedDupVec);
    std::cout << "Test Case 4 Passed (Array with duplicates)." << std::endl;

    // Test Case 5: Single Element Vector
    std::vector<int> singleVec = {42};
    std::vector<int> expectedSingleVec = {42};
    insertionSort(singleVec);
    assert(singleVec == expectedSingleVec);
    std::cout << "Test Case 5 Passed (Single element array)." << std::endl;

    // Test Case 6: Empty Vector
    std::vector<int> emptyVec;
    insertionSort(emptyVec);
    assert(emptyVec.empty());
    std::cout << "Test Case 6 Passed (Empty array)." << std::endl;

    // Test Case 7: Generic String Sorting (Alphabetical)
    std::vector<std::string> strVec = {"peach", "banana", "apple", "cherry", "date"};
    std::vector<std::string> expectedStrVec = {"apple", "banana", "cherry", "date", "peach"};
    insertionSort(strVec);
    assert(strVec == expectedStrVec);
    std::cout << "Test Case 7 Passed (Generic string array sorting)." << std::endl;

    std::cout << "\nAll Insertion Sort Tests Passed Successfully!" << std::endl;
    return 0;
}
