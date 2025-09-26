#include <bits/stdc++.h>
using namespace std;

#ifndef POWER_H
#define POWER_H

class Command {
public:
    virtual ~Command() = default;
    virtual long double execute() = 0;
};

class PowerCommand : public Command {
private:
    long double base, exp;
public:
    PowerCommand(long double b, long double e);
    long double execute() override;
};

class Invoker {
public:
    long double run(Command &cmd);
};

#endif
