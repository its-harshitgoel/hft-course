#include <iostream>
using namespace std;

struct Order {
    int price;
    double qty;
};

double totalQty(Order orders[], int n) {
    double total = 0;
    for (int i = 0; i < n; i++) {
        total += orders[i].qty;
    }
    return total;
}

int main() {
    Order ord1{200, 5};
    Order ord2{600, 2};
    Order ord3{150, 8};

    Order order[] = {ord1, ord2, ord3};
    int n = sizeof(order) / sizeof(order[0]);

    cout << totalQty(order, n) << endl;

    return 0;
}
