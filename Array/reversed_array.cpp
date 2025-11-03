#include <iostream>
#include <vector>
#include <algorithm>  // for std::reverse

using namespace std;

// Function to reverse array using two-pointer technique
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
    // Initialize the array
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> arr2 = arr; // Create a copy for second method

    // Print original array
    cout << "Original array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    // Method 1: Using STL reverse function
    reverse(arr.begin(), arr.end());
    cout << "Reversed array (STL method): ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    // Method 2: Using custom implementation
    //correct code
    reverseArrayCustom(arr2);
    cout << "Reversed array (Custom method): ";
    for (int x : arr2)
        cout << x << " ";
    cout << endl;

    return 0;
}

