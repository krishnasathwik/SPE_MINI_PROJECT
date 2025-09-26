#include "factorial.h"

long double FactorialCalculator::compute(long double x) {
    if (x < 0 || floor(x) != x || x > 20)
        return numeric_limits<long double>::quiet_NaN();
    unsigned long long res = 1;
    for (int i = 1; i <= (int)x; i++) res *= i;
    return (long double)res;
}

unique_ptr<Operation> OperationFactory::createOperation(const string &type) {
    if (type == "factorial") return make_unique<FactorialCalculator>();
    return nullptr;
}

//added to check for auto build
//check2