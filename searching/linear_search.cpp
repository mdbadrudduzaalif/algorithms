/**
 * @file linear_search.cpp
 * @brief Implementation of the Linear Search algorithm in C++.
 * 
 * Linear Search is a simple search algorithm that checks every element of a sequence
 * (like an array or vector) one by one in a linear sequence until a match is found
 * or the end of the sequence is reached.
 * 
 * Time Complexity:
 *   - Best Case: O(1) - The target is the very first element.
 *   - Average Case: O(N) - The target is somewhere in the middle.
 *   - Worst Case: O(N) - The target is the last element or not present.
 * 
 * Space Complexity:
 *   - O(1) - No extra memory is allocated.
 */

#include <iostream>
#include <vector>
#include <cassert>
#include <string>

/**
 * @brief Searches for a target value in a vector using Linear Search.
 * 
 * @tparam T The data type of the elements in the vector.
 * @param arr The input vector to search in.
 * @param target The value to search for.
 * @return int The index of the first occurrence of the target, or -1 if not found.
 */
template <typename T>
int linearSearch(const std::vector<T>& arr, const T& target) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return static_cast<int>(i); // Found the target, return its index
        }
    }
    return -1; // Target not found in the vector
}

int main() {
    std::cout << "Running Linear Search Verification Tests..." << std::endl;

    // Test Case 1: Standard Integer Search (Target in the middle)
    std::vector<int> intVec = {4, 2, 8, 5, 1, 9, 3};
    assert(linearSearch(intVec, 5) == 3);
    std::cout << "Test Case 1 Passed (Integer found in middle)." << std::endl;

    // Test Case 2: Target at the beginning (Best Case)
    assert(linearSearch(intVec, 4) == 0);
    std::cout << "Test Case 2 Passed (Integer found at beginning)." << std::endl;

    // Test Case 3: Target at the end (Worst Case)
    assert(linearSearch(intVec, 3) == 6);
    std::cout << "Test Case 3 Passed (Integer found at end)." << std::endl;

    // Test Case 4: Target not present
    assert(linearSearch(intVec, 99) == -1);
    std::cout << "Test Case 4 Passed (Integer not present)." << std::endl;

    // Test Case 5: Empty Vector
    std::vector<int> emptyVec;
    assert(linearSearch(emptyVec, 5) == -1);
    std::cout << "Test Case 5 Passed (Empty vector search)." << std::endl;

    // Test Case 6: String Search (Verifying generic template)
    std::vector<std::string> strVec = {"apple", "banana", "cherry", "date"};
    assert(linearSearch(strVec, std::string("cherry")) == 2);
    assert(linearSearch(strVec, std::string("fig")) == -1);
    std::cout << "Test Case 6 Passed (Generic string search)." << std::endl;

    std::cout << "\nAll Linear Search Tests Passed Successfully!" << std::endl;
    return 0;
}
