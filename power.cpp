#include "power.h"

PowerCommand::PowerCommand(long double b, long double e) : base(b), exp(e) {}

long double PowerCommand::execute() {
    return powl(base, exp);
}

long double Invoker::run(Command &cmd) {
    return cmd.execute();
}

//simple changee