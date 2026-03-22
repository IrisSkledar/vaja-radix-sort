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

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Uporaba: " << argv[0] << " <vhodna_datoteka>" << endl;
        return 1;
    }

    vector<int> vnos;
    if (!Branje_Stevil(vnos, argv[1])) {
        cerr << "Napaka pri branju datoteke." << endl;
        return 1;
    }

    vector<unsigned char> stevila;
    for (int val : vnos) {
        if (val < 0 || val > 255) {
            cerr << "Napaka: število izven razpona [0, 255]: " << val << endl;
            return 1;
        }
        stevila.push_back(static_cast<unsigned char>(val));
    }

    for (int k = 0; k < 8; k++) {
        countingSortByBit(stevila, k);
    }

    vector<int> izhod;
    for (unsigned char val : stevila) {
        izhod.push_back(static_cast<int>(val));
    }

    Izpis_Stevil(izhod.data(), izhod.size());

    return 0;
}