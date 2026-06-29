/**
 * @file merge_sort.cpp
 * @brief Implementation of the Merge Sort algorithm in C++.
 * 
 * Merge Sort is a stable, comparison-based, divide-and-conquer sorting algorithm.
 * It works by recursively dividing the input array into two halves, sorting the halves,
 * and then merging the sorted halves back together.
 * 
 * Time Complexity:
 *   - Best Case: O(N log N)
 *   - Average Case: O(N log N)
 *   - Worst Case: O(N log N)
 * 
 * Space Complexity:
 *   - O(N) - Temporary arrays are required for merging the sublists.
 */

#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <algorithm>

/**
 * @brief Merges two sorted subarrays of a vector back into the vector.
 * 
 * First subarray is arr[left..mid]
 * Second subarray is arr[mid+1..right]
 * 
 * @tparam T The data type of the elements in the vector (must support comparison operators).
 * @param arr The vector containing the subarrays to be merged.
 * @param left The starting index of the first subarray.
 * @param mid The ending index of the first subarray.
 * @param right The ending index of the second subarray.
 */
template <typename T>
void merge(std::vector<T>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary vectors to hold the copies of subarrays
    std::vector<T> L(n1);
    std::vector<T> R(n2);

    // Copy data to temporary vectors
    for (int i = 0; i < n1; ++i) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        R[j] = arr[mid + 1 + j];
    }

    // Merge the temporary vectors back into arr[left..right]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

/**
 * @brief Helper function that recursively divides and sorts the vector.
 * 
 * @tparam T The data type of the elements in the vector.
 * @param arr The vector to be sorted.
 * @param left The starting index of the subarray.
 * @param right The ending index of the subarray.
 */
template <typename T>
void mergeSortHelper(std::vector<T>& arr, int left, int right) {
    if (left < right) {
        // Same as (left+right)/2, but avoids overflow for large index sums
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSortHelper(arr, left, mid);
        mergeSortHelper(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

/**
 * @brief Sorts a vector of elements in ascending order using Merge Sort.
 * 
 * @tparam T The data type of the elements in the vector (must support comparison operators).
 * @param arr The input vector to be sorted.
 */
template <typename T>
void mergeSort(std::vector<T>& arr) {
    if (arr.size() <= 1) {
        return;
    }
    mergeSortHelper(arr, 0, static_cast<int>(arr.size()) - 1);
}

int main() {
    std::cout << "Running Merge Sort Verification Tests..." << std::endl;

    // Test Case 1: Standard Unsorted Integer Vector
    std::vector<int> intVec = {38, 27, 43, 3, 9, 82, 10};
    std::vector<int> expectedIntVec = {3, 9, 10, 27, 38, 43, 82};
    mergeSort(intVec);
    assert(intVec == expectedIntVec);
    std::cout << "Test Case 1 Passed (Standard unsorted integer array)." << std::endl;

    // Test Case 2: Already Sorted Vector
    std::vector<int> sortedVec = {1, 2, 3, 4, 5};
    std::vector<int> expectedSortedVec = {1, 2, 3, 4, 5};
    mergeSort(sortedVec);
    assert(sortedVec == expectedSortedVec);
    std::cout << "Test Case 2 Passed (Already sorted array)." << std::endl;

    // Test Case 3: Reverse Sorted Vector
    std::vector<int> revVec = {5, 4, 3, 2, 1};
    std::vector<int> expectedRevVec = {1, 2, 3, 4, 5};
    mergeSort(revVec);
    assert(revVec == expectedRevVec);
    std::cout << "Test Case 3 Passed (Reverse sorted array)." << std::endl;

    // Test Case 4: Vector with Duplicate Elements
    std::vector<int> dupVec = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    std::vector<int> expectedDupVec = {1, 1, 2, 3, 3, 4, 5, 5, 6, 9};
    mergeSort(dupVec);
    assert(dupVec == expectedDupVec);
    std::cout << "Test Case 4 Passed (Array with duplicates)." << std::endl;

    // Test Case 5: Single Element Vector
    std::vector<int> singleVec = {42};
    std::vector<int> expectedSingleVec = {42};
    mergeSort(singleVec);
    assert(singleVec == expectedSingleVec);
    std::cout << "Test Case 5 Passed (Single element array)." << std::endl;

    // Test Case 6: Empty Vector
    std::vector<int> emptyVec;
    mergeSort(emptyVec);
    assert(emptyVec.empty());
    std::cout << "Test Case 6 Passed (Empty array)." << std::endl;

    // Test Case 7: Generic String Sorting (Alphabetical)
    std::vector<std::string> strVec = {"peach", "banana", "apple", "cherry", "date"};
    std::vector<std::string> expectedStrVec = {"apple", "banana", "cherry", "date", "peach"};
    mergeSort(strVec);
    assert(strVec == expectedStrVec);
    std::cout << "Test Case 7 Passed (Generic string array sorting)." << std::endl;

    std::cout << "\nAll Merge Sort Tests Passed Successfully!" << std::endl;
    return 0;
}
