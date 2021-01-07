#include <iostream>
#include <vector>
#include "../stopwatch/Stopwatch.h"

using namespace std;

int main() {
    const int iter = 1e8;
    vector<int> v1, v2;

    {
        Stopwatch st("case 1 (reserve)");
        v1.reserve(iter);
        for(int i = 0; i < iter; i++) {
            v1[i] = i;
        }
    }


    {
        Stopwatch st("case 2 (push_back)");
        for(int i = 0; i < iter; i++) {
            v2.push_back(i);
        }
    }

}
