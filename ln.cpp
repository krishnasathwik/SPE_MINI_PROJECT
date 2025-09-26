#include "ln.h"

long double LnCalculator::compute(long double x) {
    if (x <= 0) return numeric_limits<long double>::quiet_NaN();
    return logl(x);
}

void CalculatorContext::setStrategy(unique_ptr<OperationStrategy> s) {
    strategy = move(s);
}

long double CalculatorContext::execute(long double x) {
    return strategy ? strategy->compute(x) : numeric_limits<long double>::quiet_NaN();
}
