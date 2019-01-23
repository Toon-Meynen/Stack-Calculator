//
// Created by tmtoon on 23.01.19.
//

#ifndef STACK_CALCULATOR_PROGRAM_HPP
#define STACK_CALCULATOR_PROGRAM_HPP


#include <vector>

template <typename T>
class Program {
private:
    std::vector<Instruction<T>*> _instructions;
    unsigned int instruction_ptr = 0;

public:
    Program<T>& operator<<(Instruction<T>*);
    bool operator()(std::stack<Data<T>>& stack);

};

template<typename T>
Program<T> &Program<T>::operator<<(Instruction<T> *i) {
    _instructions.push_back(i);
    return *this;
}

template<typename T>
bool Program<T>::operator()(std::stack<Data<T>>& stack) {
    std::cout << "IP = " << instruction_ptr << ", instruction: ";
    ++instruction_ptr;
    if (instruction_ptr > _instructions.size()) {
        throw std::out_of_range("Out of instructions");
    }
    return _instructions[instruction_ptr-1]->execute(stack);
}

#endif //STACK_CALCULATOR_PROGRAM_HPP
