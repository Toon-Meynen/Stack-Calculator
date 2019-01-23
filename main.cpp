#include <iostream>
#include "Data.hpp"
#include "Instruction.hpp"
#include "Program.hpp"
#include "StackMachine.hpp"

int main() {
    // Data:
    Data<int> a(3);
    Data<int> b(2);
    Data<int> c(5);

    // Instructions used:
    PushData<int> push_a(a);
    PushData<int> push_b(b);
    PushData<int> push_c(c);

    PrintData<int> print;
    AddData<int> add;
    SubData<int> sub;
    MulData<int> mul;
    EndProgram<int> end;

    // Program specification:
    Program<int> prog;
    prog << &push_a << &push_b << &push_c;
    prog << &add << &mul << &print;
    prog << &end;

    // Start program on machine:
    StackMachine<int> machine;
    machine.run(prog);

    return 0;
}