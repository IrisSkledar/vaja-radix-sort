#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

bool Branje_Stevil(vector<int> &vec, const char s[]) {
    ifstream input(s);
    int st;

    if (!input.is_open()) {
        return false;
    }

    while (!input.eof()) {
        input >> st;
        vec.push_back(st);
        while (isspace(input.peek())) input.get();
    }

    input.close();
    return true;
}

void Izpis_Stevil(int* polje, unsigned int velikost) {
    ofstream output("out.txt");

    for (unsigned int i = 0; i < velikost; i++) {
        output << polje[i];
        if (i < velikost - 1) output << ' ';
    }

    output << endl;
}

int getBit(unsigned char num, int k) {
    return (num >> k) & 1;
}

void countingSortByBit(vector<unsigned char>& A, int k) {
    int n = A.size();
    vector<unsigned char> output(n);
    vector<int> count(2, 0);

    vector<int> bits(n);
    for (int i = 0; i < n; i++) {
        bits[i] = getBit(A[i], k);
        count[bits[i]]++;
    }

    count[1] += count[0];

    for (int i = n - 1; i >= 0; i--) {
        int b = bits[i];
        output[--count[b]] = A[i];
    }

    A = output;
}