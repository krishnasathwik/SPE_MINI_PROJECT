#include <bits/stdc++.h>
using namespace std;

#ifndef LN_H
#define LN_H

class OperationStrategy {
public:
    virtual ~OperationStrategy() = default;
    virtual long double compute(long double x) = 0;
};

class LnCalculator : public OperationStrategy {
public:
    long double compute(long double x) override;
};

class CalculatorContext {
private:
    unique_ptr<OperationStrategy> strategy;
public:
    void setStrategy(unique_ptr<OperationStrategy> s);
    long double execute(long double x);
};

#endif
