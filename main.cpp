#include <bits/stdc++.h>
using namespace std;

#include "sqrt.h"
#include "factorial.h"
#include "ln.h"
#include "power.h"

int main() {
    cout << "=== Scientific Calculator (4 Design Patterns) ===\n";
    cout << "1) Square Root (Singleton)\n";
    cout << "2) Factorial (Factory)\n";
    cout << "3) Natural Logarithm (Strategy)\n";
    cout << "4) Power (Command)\n";
    cout << "0) Exit\n";

    while (true) {
        cout << "\nEnter option: ";
        int choice;
        if (!(cin >> choice)) break;

        if (choice == 0) { cout << "Exiting...\n"; break; }

        if (choice == 1) {
            long double x; cout << "Enter x: "; cin >> x;
            auto &calc = SqrtCalculator::getInstance();
            cout << "√" << x << " = " << calc.compute(x) << "\n";
        }
        else if (choice == 2) {
            long double x; cout << "Enter n: "; cin >> x;
            auto op = OperationFactory::createOperation("factorial");
            cout << x << "! = " << op->compute(x) << "\n";
        }
        else if (choice == 3) {
            long double x; cout << "Enter x: "; cin >> x;
            CalculatorContext ctx;
            ctx.setStrategy(make_unique<LnCalculator>());
            cout << "ln(" << x << ") = " << ctx.execute(x) << "\n";
        }
        else if (choice == 4) {
            long double a, b; cout << "Enter base: "; cin >> a;
            cout << "Enter exponent: "; cin >> b;
            PowerCommand cmd(a, b);
            Invoker inv;
            cout << a << "^" << b << " = " << inv.run(cmd) << "\n";
        }
        else {
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}
