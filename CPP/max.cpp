#include <iostream>
using namespace std;

int getMaxIndex(int arr[], int n) {
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void swapByIndex(int arr[], int n) {
    int maxIndex = getMaxIndex(arr, n);
    swap(arr[0], arr[maxIndex]);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << *arr + 2 << endl;
    swapByIndex(arr, n);


    for(auto it : arr){
        cout << it << " ";
    }

}
