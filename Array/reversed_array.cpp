#include <iostream>
#include <vector>
#include <algorithm>  // for std::reverse

using namespace std;

// Function to print array elements
void printArray(const vector<int>& arr, const string& message) {
    cout << message;
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

// Function to reverse array using two-pointer technique
// Time Complexity: O(n/2) ≈ O(n), Space Complexity: O(1)
void reverseArrayCustom(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;
    
    while (left < right) {
        // Swap elements at left and right pointers
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

int main() {
    // Test with different array sizes
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> arr2 = arr;  // Create a copy for second method
    
    // Print original array
    printArray(arr, "Original array: ");

    // Method 1: Using STL reverse function
    // Time Complexity: O(n), Space Complexity: O(1)
    reverse(arr.begin(), arr.end());
    printArray(arr, "Reversed array (STL method): ");

    // Method 2: Using custom implementation
    reverseArrayCustom(arr2);
    printArray(arr2, "Reversed array (Custom method): ");

    // Test with empty array
    vector<int> emptyArr;
    reverseArrayCustom(emptyArr);
    printArray(emptyArr, "Empty array test: ");

    // Test with single element
    vector<int> singleArr = {1};
    reverseArrayCustom(singleArr);
    printArray(singleArr, "Single element array test: ");

    return 0;
}

