//
// Created by tmtoon on 23.01.19.
//

#ifndef STACK_CALCULATOR_STACKMACHINE_HPP
#define STACK_CALCULATOR_STACKMACHINE_HPP

template<typename T>
class StackMachine {
private:
    std::stack<Data<T>> _data;

public:
    void run(Program<T>&);
};

template<typename T>
void StackMachine<T>::run(Program<T> &p) {
    std::cout << "Machine started!" << std::endl;
    try {
        while (not p(_data));
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

#endif //STACK_CALCULATOR_STACKMACHINE_HPP
