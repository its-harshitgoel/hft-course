#include <iostream>
#include <cmath>
using namespace std;

struct ORDER
{
    int orderid;
    bool isBid;
    int price, qty;

    void qtySetter(int qty)
    {
        this->qty = qty;
    }
};


struct RESPONSE
{
    int qtyFilled;
};

RESPONSE matchOrders(ORDER &a, ORDER &b)
{

    if (a.isBid == b.isBid)
    {
        return RESPONSE{0};
    }

    ORDER &bid = a.isBid ? a : b;
    ORDER &ask = a.isBid ? b : a;

    if (bid.price >= ask.price)
    {
        int fillQty = min(bid.qty, ask.qty);
        bid.qtySetter(bid.qty - fillQty);
        ask.qtySetter(ask.qty - fillQty);
        return RESPONSE{fillQty};
    }

    return RESPONSE{0};
}

int main()

{
    
    ORDER John{145, true, 10, 3};
    ORDER Jacob{344, false, 5, 2};

    RESPONSE resp = matchOrders(John, Jacob);

    cout << Jacob.qty << endl;

    cout << resp.qtyFilled << endl;
}