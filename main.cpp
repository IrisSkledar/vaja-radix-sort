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
