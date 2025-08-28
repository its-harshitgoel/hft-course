#include <iostream>
using namespace std;

int main() {
    int N = 3;
    int M = 4;

    int** arr = new int*[N];

    for (int i = 0; i < N; i++) {
        arr[i] = new int[M];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            arr[i][j] = i * M + j;  // just for demo
        }
    }

    for (int i = 0; i < N && i < M; i++) {
        cout << arr[i][i] << endl;
    }

    // // Free memory
    // for (int i = 0; i < N; i++) {
    //     delete[] arr[i];
    // }
    // delete[] arr;

    // return 0;
}
