#include "sqrt.h"

SqrtCalculator::SqrtCalculator() {}

SqrtCalculator& SqrtCalculator::getInstance() {
    static SqrtCalculator instance;
    return instance;
}

long double SqrtCalculator::compute(long double x) {
    if (x < 0) return numeric_limits<long double>::quiet_NaN();
    return sqrtl(x);
}
