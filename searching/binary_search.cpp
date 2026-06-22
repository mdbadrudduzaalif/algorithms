/**
 * @file binary_search.cpp
 * @brief Implementation of the Binary Search algorithm in C++.
 * 
 * Binary Search is an efficient algorithm for finding an item from a sorted list of items.
 * It works by repeatedly dividing in half the portion of the list that could contain the item,
 * until you've narrowed down the possible locations to just one.
 * 
 * NOTE: The input vector MUST be sorted for Binary Search to work correctly.
 * 
 * Time Complexity:
 *   - Best Case: O(1) - The target is the middle element.
 *   - Average Case: O(log N) - The search space is halved in each step.
 *   - Worst Case: O(log N) - The target is at the ends or not present.
 * 
 * Space Complexity:
 *   - O(1) - Iterative approach uses constant extra memory.
 */

#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <algorithm>

/**
 * @brief Searches for a target value in a sorted vector using iterative Binary Search.
 * 
 * @tparam T The data type of the elements in the vector (must support comparison operators).
 * @param arr The sorted input vector to search in.
 * @param target The value to search for.
 * @return int The index of the target element, or -1 if not found.
 */
template <typename T>
int binarySearch(const std::vector<T>& arr, const T& target) {
    if (arr.empty()) {
        return -1;
    }

    int left = 0;
    int right = static_cast<int>(arr.size()) - 1;

    while (left <= right) {
        // Prevents potential overflow compared to (left + right) / 2
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] < target) {
            left = mid + 1; // Search the right half
        } else {
            right = mid - 1; // Search the left half
        }
    }

    return -1; // Target not found
}

int main() {
    std::cout << "Running Binary Search Verification Tests..." << std::endl;

    // Test Case 1: Standard Sorted Integer Search (Target in the middle)
    std::vector<int> sortedVec = {1, 3, 5, 7, 9, 11, 13, 15};
    assert(binarySearch(sortedVec, 7) == 3);
    std::cout << "Test Case 1 Passed (Integer found in middle)." << std::endl;

    // Test Case 2: Target at the beginning (leftmost index)
    assert(binarySearch(sortedVec, 1) == 0);
    std::cout << "Test Case 2 Passed (Integer found at beginning)." << std::endl;

    // Test Case 3: Target at the end (rightmost index)
    assert(binarySearch(sortedVec, 15) == 7);
    std::cout << "Test Case 3 Passed (Integer found at end)." << std::endl;

    // Test Case 4: Target not present (smaller than any element)
    assert(binarySearch(sortedVec, 0) == -1);
    std::cout << "Test Case 4 Passed (Target too small not found)." << std::endl;

    // Test Case 5: Target not present (larger than any element)
    assert(binarySearch(sortedVec, 20) == -1);
    std::cout << "Test Case 5 Passed (Target too large not found)." << std::endl;

    // Test Case 6: Empty Vector
    std::vector<int> emptyVec;
    assert(binarySearch(emptyVec, 5) == -1);
    std::cout << "Test Case 6 Passed (Empty vector search)." << std::endl;

    // Test Case 7: Single Element Vector (Found)
    std::vector<int> singleVec = {42};
    assert(binarySearch(singleVec, 42) == 0);
    assert(binarySearch(singleVec, 10) == -1);
    std::cout << "Test Case 7 Passed (Single element vector search)." << std::endl;

    // Test Case 8: Generic String Search (Verifying generic template)
    std::vector<std::string> strVec = {"apple", "banana", "cherry", "date", "fig", "grape"};
    // Ensure it's sorted alphabetically
    assert(std::is_sorted(strVec.begin(), strVec.end()));
    assert(binarySearch(strVec, std::string("cherry")) == 2);
    assert(binarySearch(strVec, std::string("date")) == 3);
    assert(binarySearch(strVec, std::string("kiwi")) == -1);
    std::cout << "Test Case 8 Passed (Generic sorted string search)." << std::endl;

    std::cout << "\nAll Binary Search Tests Passed Successfully!" << std::endl;
    return 0;
}
