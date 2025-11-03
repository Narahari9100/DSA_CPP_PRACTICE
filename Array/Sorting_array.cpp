#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

// Function to print array with indices
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

// Bubble Sort Implementation
// Time Complexity: O(n²), Space Complexity: O(1)
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // If no swapping occurred, array is already sorted
        if (!swapped)
            break;
    }
}

// Selection Sort Implementation
// Time Complexity: O(n²), Space Complexity: O(1)
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
        }
    }
}

// Insertion Sort Implementation
// Time Complexity: O(n²), Space Complexity: O(1)
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Quick Sort Implementation
// Time Complexity: O(n log n) average, O(n²) worst case
// Space Complexity: O(log n)
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Merge Sort Implementation
// Time Complexity: O(n log n), Space Complexity: O(n)
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    vector<int> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
        
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    try {
        // Test data
        vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
        
        cout << "\n=== Sorting Algorithm Demonstrations ===\n";
        
        // Bubble Sort
        vector<int> bubbleArr = arr;
        printArray(bubbleArr, "Original Array for Bubble Sort:");
        bubbleSort(bubbleArr);
        printArray(bubbleArr, "After Bubble Sort:");
        
        // Selection Sort
        vector<int> selectionArr = arr;
        printArray(selectionArr, "Original Array for Selection Sort:");
        selectionSort(selectionArr);
        printArray(selectionArr, "After Selection Sort:");
        
        // Insertion Sort
        vector<int> insertionArr = arr;
        printArray(insertionArr, "Original Array for Insertion Sort:");
        insertionSort(insertionArr);
        printArray(insertionArr, "After Insertion Sort:");
        
        // Quick Sort
        vector<int> quickArr = arr;
        printArray(quickArr, "Original Array for Quick Sort:");
        quickSort(quickArr, 0, quickArr.size() - 1);
        printArray(quickArr, "After Quick Sort:");
        
        // Merge Sort
        vector<int> mergeArr = arr;
        printArray(mergeArr, "Original Array for Merge Sort:");
        mergeSort(mergeArr, 0, mergeArr.size() - 1);
        printArray(mergeArr, "After Merge Sort:");
        
        // STL Sort (for comparison)
        vector<int> stlArr = arr;
        printArray(stlArr, "Original Array for STL Sort:");
        sort(stlArr.begin(), stlArr.end());
        printArray(stlArr, "After STL Sort:");

        // Edge Cases
        cout << "\n=== Edge Cases ===\n";
        vector<int> emptyArr;
        printArray(emptyArr, "Empty Array Test:");
        
        vector<int> singleArr = {1};
        printArray(singleArr, "Single Element Array:");
        bubbleSort(singleArr);
        printArray(singleArr, "After Sorting Single Element Array:");
        
    } catch (const exception& e) {
        cerr << "Error in main: " << e.what() << endl;
        return 1;
    }

    return 0;
}
