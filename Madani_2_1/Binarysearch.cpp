#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& lst, int find) {
    int left = 0;
    int right = lst.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (lst[mid] == find)
            return mid;

        if (lst[mid] < find)
            left = mid + 1;

        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    vector<int> lst = {};
    int find;
    cin >> find;
    int index = binarySearch(lst, find);
    if (index != -1)
        cout << "Element found at index " << index;
    else
        cout << "Element not found in the array";
    return 0;
}
