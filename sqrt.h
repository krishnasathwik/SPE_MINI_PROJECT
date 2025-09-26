#include <bits/stdc++.h>
using namespace std;

#ifndef SQRT_H
#define SQRT_H

class SqrtCalculator {
private:
    SqrtCalculator();
public:
    SqrtCalculator(const SqrtCalculator&) = delete;
    SqrtCalculator& operator=(const SqrtCalculator&) = delete;

    static SqrtCalculator& getInstance();
    long double compute(long double x);
};

#endif
