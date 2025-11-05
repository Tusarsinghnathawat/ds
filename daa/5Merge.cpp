#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Function to merge two sorted halves
void merge(vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// Regular recursive merge sort
void mergeSort(vector<int> &arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// Multithreaded merge sort
void threadedMergeSort(vector<int> &arr, int left, int right, int depth = 0) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;

    // Limit recursion depth for threads (avoid too many threads)
    if (depth >= 3) { // adjust for your system
        mergeSort(arr, left, right);
        return;
    }

    thread t1([&]() { threadedMergeSort(arr, left, mid, depth + 1); });
    thread t2([&]() { threadedMergeSort(arr, mid + 1, right, depth + 1); });

    t1.join();
    t2.join();
    merge(arr, left, mid, right);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> arr1 = arr;
    vector<int> arr2 = arr;

    // --- Regular Merge Sort ---
    auto start1 = high_resolution_clock::now();
    mergeSort(arr1, 0, n - 1);
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(end1 - start1).count();

    // --- Multithreaded Merge Sort ---
    auto start2 = high_resolution_clock::now();
    threadedMergeSort(arr2, 0, n - 1);
    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(end2 - start2).count();

    cout << "\nSorted array:\n";
    for (auto x : arr2) cout << x << " ";
    cout << "\n\nTime taken by Merge Sort: " << duration1 << " ms";
    cout << "\nTime taken by Multithreaded Merge Sort: " << duration2 << " ms\n";

    return 0;
}

// Time: O(nlogn)

// Merge Sort:
// - Splits array recursively into halves.
// - Sorts each half.
// - Merges sorted halves.

// Multithreaded Merge Sort:
// - Creates a thread for each half to sort in parallel.
// - Waits for both threads to finish.
// - Then merges results.
// - Thread depth is limited to prevent CPU overload.