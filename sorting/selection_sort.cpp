/**
 * @file selection_sort.cpp
 * @brief Implementation of the Selection Sort algorithm in C++.
 * 
 * Selection Sort is a simple comparison-based sorting algorithm. The algorithm divides the input
 * list into two parts: a sorted sublist of items which is built up from left to right at the front,
 * and a sublist of the remaining unsorted items.
 * 
 * In each iteration, it finds the minimum element from the unsorted sublist and swaps it
 * with the leftmost unsorted element, moving the sublist boundary one element to the right.
 * 
 * Time Complexity:
 *   - Best Case: O(N^2) - Still does comparison loops even if array is sorted.
 *   - Average Case: O(N^2)
 *   - Worst Case: O(N^2)
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
 * @brief Sorts a vector of elements in ascending order using Selection Sort.
 * 
 * @tparam T The data type of the elements in the vector (must support comparison operators).
 * @param arr The input vector to be sorted.
 */
template <typename T>
void selectionSort(std::vector<T>& arr) {
    if (arr.size() <= 1) {
        return;
    }

    size_t n = arr.size();
    for (size_t i = 0; i < n - 1; ++i) {
        size_t minIndex = i;

        // Find the index of the minimum element in the remaining unsorted array
        for (size_t j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element of the unsorted part
        if (minIndex != i) {
            std::swap(arr[i], arr[minIndex]);
        }
    }
}

int main() {
    std::cout << "Running Selection Sort Verification Tests..." << std::endl;

    // Test Case 1: Standard Unsorted Integer Vector
    std::vector<int> intVec = {29, 10, 14, 37, 13};
    std::vector<int> expectedIntVec = {10, 13, 14, 29, 37};
    selectionSort(intVec);
    assert(intVec == expectedIntVec);
    std::cout << "Test Case 1 Passed (Standard unsorted integer array)." << std::endl;

    // Test Case 2: Already Sorted Vector (Verifying functionality remains correct)
    std::vector<int> sortedVec = {1, 2, 3, 4, 5};
    std::vector<int> expectedSortedVec = {1, 2, 3, 4, 5};
    selectionSort(sortedVec);
    assert(sortedVec == expectedSortedVec);
    std::cout << "Test Case 2 Passed (Already sorted array)." << std::endl;

    // Test Case 3: Reverse Sorted Vector (Worst Case)
    std::vector<int> revVec = {5, 4, 3, 2, 1};
    std::vector<int> expectedRevVec = {1, 2, 3, 4, 5};
    selectionSort(revVec);
    assert(revVec == expectedRevVec);
    std::cout << "Test Case 3 Passed (Reverse sorted array)." << std::endl;

    // Test Case 4: Vector with Duplicate Elements
    std::vector<int> dupVec = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    std::vector<int> expectedDupVec = {1, 1, 2, 3, 3, 4, 5, 5, 6, 9};
    selectionSort(dupVec);
    assert(dupVec == expectedDupVec);
    std::cout << "Test Case 4 Passed (Array with duplicates)." << std::endl;

    // Test Case 5: Single Element Vector
    std::vector<int> singleVec = {42};
    std::vector<int> expectedSingleVec = {42};
    selectionSort(singleVec);
    assert(singleVec == expectedSingleVec);
    std::cout << "Test Case 5 Passed (Single element array)." << std::endl;

    // Test Case 6: Empty Vector
    std::vector<int> emptyVec;
    selectionSort(emptyVec);
    assert(emptyVec.empty());
    std::cout << "Test Case 6 Passed (Empty array)." << std::endl;

    // Test Case 7: Generic String Sorting (Alphabetical)
    std::vector<std::string> strVec = {"peach", "banana", "apple", "cherry", "date"};
    std::vector<std::string> expectedStrVec = {"apple", "banana", "cherry", "date", "peach"};
    selectionSort(strVec);
    assert(strVec == expectedStrVec);
    std::cout << "Test Case 7 Passed (Generic string array sorting)." << std::endl;

    std::cout << "\nAll Selection Sort Tests Passed Successfully!" << std::endl;
    return 0;
}
