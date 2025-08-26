#include <iostream>
#include <vector>
#include <string>
#include <bitset>
using namespace std;

struct EndianResult {
    vector<string> bigEndian;
    vector<string> littleEndian;
    unsigned long long bigInt;
    unsigned long long littleInt;
};

string normalizeToByte(const string &s) {
    if (s.size() > 8) return s.substr(s.size() - 8);
    if (s.size() < 8) return string(8 - s.size(), '0') + s;
    return s;
}

EndianResult getEndian(const char* arr[], int size) {
    EndianResult result;
    vector<string> normalized;

    for (int i = 0; i < size; i++) {
        normalized.push_back(normalizeToByte(arr[i]));
    }

    // big endian order
    result.bigEndian = normalized;

    // little endian order
    for (int i = size - 1; i >= 0; i--) {
        result.littleEndian.push_back(normalized[i]);
    }

    // convert big endian to int
    result.bigInt = 0;
    for (auto &b : result.bigEndian) {
        result.bigInt = (result.bigInt << 8) | bitset<8>(b).to_ulong();
    }

    // convert little endian to int
    result.littleInt = 0;
    for (auto &b : result.littleEndian) {
        result.littleInt = (result.littleInt << 8) | bitset<8>(b).to_ulong();
    }

    return result;
}

int main() {
    const char* arr[] = {"000000101", "000000001", "00000010"};
    int size = sizeof(arr) / sizeof(arr[0]);

    EndianResult res = getEndian(arr, size);

    cout << "Big Endian Bytes   : ";
    for (auto &b : res.bigEndian) cout << b << " ";
    cout << endl;

    cout << "Little Endian Bytes: ";
    for (auto &l : res.littleEndian) cout << l << " ";
    cout << endl;

    cout << "Big Endian Int     : " << res.bigInt << endl;
    cout << "Little Endian Int  : " << res.littleInt << endl;

    return 0;
}
