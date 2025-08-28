#include <iostream>
using namespace std;

int* f(){
    int x = 2;
    return &x;
}

int main(){
    int* x = f();
 
    cout << *x << endl;
}