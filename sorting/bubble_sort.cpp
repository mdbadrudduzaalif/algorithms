/**
 * @file bubble_sort.cpp
 * @brief Implementation of the Bubble Sort algorithm in C++.
 * 
 * Bubble Sort is a simple comparison-based sorting algorithm. It repeatedly steps
 * through the list, compares adjacent elements, and swaps them if they are in the wrong order.
 * The pass through the list is repeated until the list is sorted.
 * 
 * Optimization:
 *   - By tracking whether a swap occurred during a pass, we can terminate the algorithm
 *     early if the list becomes sorted before all passes are completed.
 * 
 * Time Complexity:
 *   - Best Case: O(N) - The input array is already sorted (with swap optimization).
 *   - Average Case: O(N^2) - Average distribution of elements.
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
 * @brief Sorts a vector of elements in ascending order using Bubble Sort.
 * 
 * @tparam T The data type of the elements in the vector (must support comparison operators).
 * @param arr The input vector to be sorted.
 */
template <typename T>
void bubbleSort(std::vector<T>& arr) {
    if (arr.size() <= 1) {
        return;
    }

    size_t n = arr.size();
    for (size_t i = 0; i < n - 1; ++i) {
        bool swapped = false;

        // Last i elements are already in place
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped by inner loop, then the array is sorted
        if (!swapped) {
            break;
        }
    }
}

int main() {
    std::cout << "Running Bubble Sort Verification Tests..." << std::endl;

    // Test Case 1: Standard Unsorted Integer Vector
    std::vector<int> intVec = {64, 34, 25, 12, 22, 11, 90};
    std::vector<int> expectedIntVec = {11, 12, 22, 25, 34, 64, 90};
    bubbleSort(intVec);
    assert(intVec == expectedIntVec);
    std::cout << "Test Case 1 Passed (Standard unsorted integer array)." << std::endl;

    // Test Case 2: Already Sorted Vector (Verifying Best Case)
    std::vector<int> sortedVec = {1, 2, 3, 4, 5};
    std::vector<int> expectedSortedVec = {1, 2, 3, 4, 5};
    bubbleSort(sortedVec);
    assert(sortedVec == expectedSortedVec);
    std::cout << "Test Case 2 Passed (Already sorted array)." << std::endl;

    // Test Case 3: Reverse Sorted Vector (Worst Case)
    std::vector<int> revVec = {5, 4, 3, 2, 1};
    std::vector<int> expectedRevVec = {1, 2, 3, 4, 5};
    bubbleSort(revVec);
    assert(revVec == expectedRevVec);
    std::cout << "Test Case 3 Passed (Reverse sorted array)." << std::endl;

    // Test Case 4: Vector with Duplicate Elements
    std::vector<int> dupVec = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    std::vector<int> expectedDupVec = {1, 1, 2, 3, 3, 4, 5, 5, 6, 9};
    bubbleSort(dupVec);
    assert(dupVec == expectedDupVec);
    std::cout << "Test Case 4 Passed (Array with duplicates)." << std::endl;

    // Test Case 5: Single Element Vector
    std::vector<int> singleVec = {42};
    std::vector<int> expectedSingleVec = {42};
    bubbleSort(singleVec);
    assert(singleVec == expectedSingleVec);
    std::cout << "Test Case 5 Passed (Single element array)." << std::endl;

    // Test Case 6: Empty Vector
    std::vector<int> emptyVec;
    bubbleSort(emptyVec);
    assert(emptyVec.empty());
    std::cout << "Test Case 6 Passed (Empty array)." << std::endl;

    // Test Case 7: Generic String Sorting (Alphabetical)
    std::vector<std::string> strVec = {"peach", "banana", "apple", "cherry", "date"};
    std::vector<std::string> expectedStrVec = {"apple", "banana", "cherry", "date", "peach"};
    bubbleSort(strVec);
    assert(strVec == expectedStrVec);
    std::cout << "Test Case 7 Passed (Generic string array sorting)." << std::endl;

    std::cout << "\nAll Bubble Sort Tests Passed Successfully!" << std::endl;
    return 0;
}
