/**
 * @file quick_sort.cpp
 * @brief Implementation of the Quick Sort algorithm in C++.
 * 
 * Quick Sort is an efficient, comparison-based, divide-and-conquer sorting algorithm.
 * It works by selecting a 'pivot' element from the array and partitioning the other
 * elements into two subarrays according to whether they are less than or greater than the pivot.
 * The subarrays are then sorted recursively.
 * 
 * This implementation uses Hoare's partition scheme, which is generally more efficient
 * than Lomuto's partition scheme as it does fewer swaps on average.
 * 
 * Time Complexity:
 *   - Best Case: O(N log N)
 *   - Average Case: O(N log N)
 *   - Worst Case: O(N^2) - When the pivot is consistently the smallest or largest element.
 * 
 * Space Complexity:
 *   - O(log N) - Auxiliary space required for recursive call stack.
 */

#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <algorithm>

/**
 * @brief Partitions the vector using Hoare's partition scheme.
 * 
 * @tparam T The data type of the elements in the vector (must support comparison operators).
 * @param arr The vector to partition.
 * @param low The starting index of the subarray.
 * @param high The ending index of the subarray.
 * @return int The pivot index.
 */
template <typename T>
int partition(std::vector<T>& arr, int low, int high) {
    T pivot = arr[low + (high - low) / 2]; // Midpoint pivot
    int i = low - 1;
    int j = high + 1;

    while (true) {
        // Find leftmost element greater than or equal to pivot
        do {
            ++i;
        } while (arr[i] < pivot);

        // Find rightmost element smaller than or equal to pivot
        do {
            --j;
        } while (arr[j] > pivot);

        // If two pointers met
        if (i >= j) {
            return j;
        }

        std::swap(arr[i], arr[j]);
    }
}

/**
 * @brief Helper function that recursively sorts the partitioned subarrays.
 * 
 * @tparam T The data type of the elements in the vector.
 * @param arr The vector to be sorted.
 * @param low The starting index of the subarray.
 * @param high The ending index of the subarray.
 */
template <typename T>
void quickSortHelper(std::vector<T>& arr, int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);

        // Recursively sort elements before partition and after partition
        quickSortHelper(arr, low, p);
        quickSortHelper(arr, p + 1, high);
    }
}

/**
 * @brief Sorts a vector of elements in ascending order using Quick Sort.
 * 
 * @tparam T The data type of the elements in the vector (must support comparison operators).
 * @param arr The input vector to be sorted.
 */
template <typename T>
void quickSort(std::vector<T>& arr) {
    if (arr.size() <= 1) {
        return;
    }
    quickSortHelper(arr, 0, static_cast<int>(arr.size()) - 1);
}

int main() {
    std::cout << "Running Quick Sort Verification Tests..." << std::endl;

    // Test Case 1: Standard Unsorted Integer Vector
    std::vector<int> intVec = {10, 7, 8, 9, 1, 5};
    std::vector<int> expectedIntVec = {1, 5, 7, 8, 9, 10};
    quickSort(intVec);
    assert(intVec == expectedIntVec);
    std::cout << "Test Case 1 Passed (Standard unsorted integer array)." << std::endl;

    // Test Case 2: Already Sorted Vector
    std::vector<int> sortedVec = {1, 2, 3, 4, 5};
    std::vector<int> expectedSortedVec = {1, 2, 3, 4, 5};
    quickSort(sortedVec);
    assert(sortedVec == expectedSortedVec);
    std::cout << "Test Case 2 Passed (Already sorted array)." << std::endl;

    // Test Case 3: Reverse Sorted Vector
    std::vector<int> revVec = {5, 4, 3, 2, 1};
    std::vector<int> expectedRevVec = {1, 2, 3, 4, 5};
    quickSort(revVec);
    assert(revVec == expectedRevVec);
    std::cout << "Test Case 3 Passed (Reverse sorted array)." << std::endl;

    // Test Case 4: Vector with Duplicate Elements
    std::vector<int> dupVec = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    std::vector<int> expectedDupVec = {1, 1, 2, 3, 3, 4, 5, 5, 6, 9};
    quickSort(dupVec);
    assert(dupVec == expectedDupVec);
    std::cout << "Test Case 4 Passed (Array with duplicates)." << std::endl;

    // Test Case 5: Single Element Vector
    std::vector<int> singleVec = {42};
    std::vector<int> expectedSingleVec = {42};
    quickSort(singleVec);
    assert(singleVec == expectedSingleVec);
    std::cout << "Test Case 5 Passed (Single element array)." << std::endl;

    // Test Case 6: Empty Vector
    std::vector<int> emptyVec;
    quickSort(emptyVec);
    assert(emptyVec.empty());
    std::cout << "Test Case 6 Passed (Empty array)." << std::endl;

    // Test Case 7: Generic String Sorting (Alphabetical)
    std::vector<std::string> strVec = {"peach", "banana", "apple", "cherry", "date"};
    std::vector<std::string> expectedStrVec = {"apple", "banana", "cherry", "date", "peach"};
    quickSort(strVec);
    assert(strVec == expectedStrVec);
    std::cout << "Test Case 7 Passed (Generic string array sorting)." << std::endl;

    std::cout << "\nAll Quick Sort Tests Passed Successfully!" << std::endl;
    return 0;
}
