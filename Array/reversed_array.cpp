#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    cout << "Original array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    reverse(arr.begin(), arr.end());

    cout << "Reversed array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
