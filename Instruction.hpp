//
// Created by tmtoon on 23.01.19.
//

#ifndef STACK_CALCULATOR_INSTRUCTION_HPP
#define STACK_CALCULATOR_INSTRUCTION_HPP

#include <stack>
#include <vector>
#include "Data.hpp"

template <typename T>
class Instruction {
public:
    virtual bool execute(std::stack<Data<T>>& stack) const = 0;
};

template <typename T>
class PushData : public Instruction<T> {
private:
    Data<T> _data;

public:
    bool execute(std::stack<Data<T>>& stack) const override;

    explicit PushData(const Data<T>& d) :_data(d) {}
};

template <typename T>
class AddData : public Instruction<T> {
public:
    bool execute(std::stack<Data<T>>& stack) const override;

};

template <typename T>
class SubData : public Instruction<T> {
public:
    bool execute(std::stack<Data<T>>& stack) const override;

};

template <typename T>
class MulData : public Instruction<T> {
public:
    bool execute(std::stack<Data<T>>& stack) const override;

};

template <typename T>
class DivData : public Instruction<T> {
public:
    bool execute(std::stack<Data<T>>& stack) const override;

};

template <typename T>
class PrintData : public Instruction<T> {
public:
    bool execute(std::stack<Data<T>>& stack) const override;

};

template <typename T>
class EndProgram : public Instruction<T> {
public:
    bool execute(std::stack<Data<T>>& stack) const override;

};

template<typename T>
bool PushData<T>::execute(std::stack<Data<T>> &stack) const {
    std::cout << "PushData (Data = Data (value = " << _data.get() << "))" << std::endl;
    std::cout << "PushData pushed a Data (value = " << _data.get() << ")" << std::endl;
    stack.push(_data);
    return false;
}

template<typename T>
bool AddData<T>::execute(std::stack<Data<T>> &stack) const {
    std::cout << "AddData" << std::endl;
    if (stack.size() < 2) {
        throw std::underflow_error("AddData: stack underflow");
    }
    auto a = stack.top();
    std::cout << "AddData popped a Data (value = " << a.get() << ")" << std::endl;
    stack.pop();
    auto b = stack.top();
    std::cout << "AddData popped a Data (value = " << b.get() << ")" << std::endl;
    stack.pop();
    a += b;
    stack.push(a);
    std::cout << "AddData pushed a Data (value = " << a.get() << ")" << std::endl;
    return false;
}

template<typename T>
bool SubData<T>::execute(std::stack<Data<T>> &stack) const {
    std::cout << "SubData" << std::endl;
    if (stack.size() < 2) {
        throw std::underflow_error("SubData: stack underflow");
    }
    auto a = stack.top();
    std::cout << "SubData popped a Data (value = " << a.get() << ")" << std::endl;
    stack.pop();
    auto b = stack.top();
    std::cout << "SubData popped a Data (value = " << b.get() << ")" << std::endl;
    stack.pop();
    a -= b;
    std::cout << "SubData pushed a Data (value = " << a.get() << ")" << std::endl;
    stack.push(a);
    return false;
}

template<typename T>
bool MulData<T>::execute(std::stack<Data<T>> &stack) const {
    std::cout << "MulData" << std::endl;
    if (stack.size() < 2) {
        throw std::underflow_error("MulData: stack underflow");
    }
    auto a = stack.top();
    std::cout << "MulData popped a Data (value = " << a.get() << ")" << std::endl;
    stack.pop();
    auto b = stack.top();
    std::cout << "MulData popped a Data (value = " << b.get() << ")" << std::endl;
    stack.pop();
    a *= b;
    std::cout << "MulData pushed a Data (value = " << a.get() << ")" << std::endl;
    stack.push(a);
    return false;
}

template<typename T>
bool DivData<T>::execute(std::stack<Data<T>> &stack) const {
    std::cout << "DivData" << std::endl;
    if (stack.size() < 2) {
        throw std::underflow_error("DivData: stack underflow");
    }
    auto a = stack.top();
    std::cout << "DivData popped a Data (value = " << a.get() << ")" << std::endl;
    stack.pop();
    auto b = stack.top();
    std::cout << "DivData popped a Data (value = " << b.get() << ")" << std::endl;
    stack.pop();
    a /= b;
    std::cout << "DivData pushed a Data (value = " << a.get() << ")" << std::endl;
    stack.push(a);
    return false;
}

template<typename T>
bool PrintData<T>::execute(std::stack<Data<T>> &stack) const {
    std::cout << "PrintData" << std::endl;
    if (stack.size() < 1) {
        throw std::underflow_error("PrintData: stack underflow");
    }
    stack.top().print();
    std::cout << std::endl;
    return false;
}

template<typename T>
bool EndProgram<T>::execute(std::stack<Data<T>> &) const {
    std::cout << "EndProgram" << std::endl;
    return true;
}

#endif //STACK_CALCULATOR_INSTRUCTION_HPP
