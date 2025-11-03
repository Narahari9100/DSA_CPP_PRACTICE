#include <iostream>
#include <vector>
#include <algorithm>  // for std::reverse
#include <stdexcept> // for exception handling

using namespace std;

// Function to print array elements with index positions
void printArray(const vector<int>& arr, const string& message) {
    cout << message << endl;
    if (arr.empty()) {
        cout << "Array is empty!" << endl;
        return;
    }
    
    cout << "Index: ";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << i << "\t";
    }
    cout << "\nValue: ";
    for (int x : arr) {
        cout << x << "\t";
    }
    cout << "\n" << string(50, '-') << endl;
}

// Function to reverse array using two-pointer technique
// Time Complexity: O(n/2) ≈ O(n), Space Complexity: O(1)
void reverseArrayCustom(vector<int>& arr) {
    try {
        int left = 0;
        int right = arr.size() - 1;
        
        while (left < right) {
            // Swap elements at left and right pointers
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    } catch (const exception& e) {
        cerr << "Error in reverseArrayCustom: " << e.what() << endl;
    }
}

// Function to reverse array in specified range [start, end]
void reverseArrayRange(vector<int>& arr, size_t start, size_t end) {
    if (arr.empty()) {
        throw runtime_error("Array is empty");
    }
    if (start >= arr.size() || end >= arr.size() || start > end) {
        throw runtime_error("Invalid range specified");
    }
    
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main() {
    try {
        cout << "\n=== Basic Array Reversal Tests ===\n";
        // Test with different array sizes
        vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        vector<int> arr2 = arr;  // Create a copy for second method
        
        // Print original array
        printArray(arr, "Original array:");

        // Method 1: Using STL reverse function
        reverse(arr.begin(), arr.end());
        printArray(arr, "Reversed array (STL method):");

        // Method 2: Using custom implementation
        reverseArrayCustom(arr2);
        printArray(arr2, "Reversed array (Custom method):");

        cout << "\n=== Edge Cases ===\n";
        // Test with empty array
        vector<int> emptyArr;
        printArray(emptyArr, "Empty array test:");
        
        // Test with single element
        vector<int> singleArr = {42};
        printArray(singleArr, "Single element array (before):");
        reverseArrayCustom(singleArr);
        printArray(singleArr, "Single element array (after):");

        cout << "\n=== Range Reversal Tests ===\n";
        // Test reversing specific ranges
        vector<int> rangeArr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        printArray(rangeArr, "Original array for range reversal:");
        
        // Reverse first half
        reverseArrayRange(rangeArr, 0, 4);
        printArray(rangeArr, "After reversing first half [0-4]:");
        
        // Reverse second half
        reverseArrayRange(rangeArr, 5, 9);
        printArray(rangeArr, "After reversing second half [5-9]:");

        cout << "\n=== Error Handling Tests ===\n";
        // Test invalid range
        try {
            reverseArrayRange(rangeArr, 8, 2);
            cout << "This line shouldn't be reached!" << endl;
        } catch (const runtime_error& e) {
            cout << "Successfully caught error: " << e.what() << endl;
        }

        // Test out of bounds range
        try {
            reverseArrayRange(rangeArr, 0, rangeArr.size());
            cout << "This line shouldn't be reached!" << endl;
        } catch (const runtime_error& e) {
            cout << "Successfully caught error: " << e.what() << endl;
        }

    } catch (const exception& e) {
        cerr << "Error in main: " << e.what() << endl;
        return 1;
    }

    return 0;
}

