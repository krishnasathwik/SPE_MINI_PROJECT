#include <bits/stdc++.h>
using namespace std;

#ifndef FACTORIAL_H
#define FACTORIAL_H

class Operation {
public:
    virtual ~Operation() = default;
    virtual long double compute(long double x) = 0;
};

class FactorialCalculator : public Operation {
public:
    long double compute(long double x) override;
};

class OperationFactory {
public:
    static unique_ptr<Operation> createOperation(const string &type);
};

#endif
