//
// Created by tmtoon on 23.01.19.
//

#ifndef STACK_CALCULATOR_DATA_HPP
#define STACK_CALCULATOR_DATA_HPP

#include <iostream>

template <typename T>
class Data {
private:
    T _data;

public:
    explicit Data(const T&);

    Data<T>& operator+=(const Data<T>&);

    Data<T>& operator-=(const Data<T>&);

    Data<T>& operator*=(const Data<T>&);

    Data<T>& operator/=(const Data<T>&);

    void print() const;

    const T& get() const;
};

template<typename T>
Data<T>::Data(const T &val) : _data(val){

}

template<typename T>
Data<T> &Data<T>::operator+=(const Data<T> &rhs) {
    _data += rhs._data;
    return *this;
}

template<typename T>
Data<T> &Data<T>::operator-=(const Data<T> &rhs) {
    _data -= rhs._data;
    return *this;
}

template<typename T>
Data<T> &Data<T>::operator*=(const Data<T> &rhs) {
    _data *= rhs._data;
    return *this;
}

template<typename T>
Data<T> &Data<T>::operator/=(const Data<T> &rhs) {
    _data /= rhs._data;
    return *this;
}

template<typename T>
void Data<T>::print() const {
    std::cout << _data;
}

template<typename T>
const T &Data<T>::get() const {
    return _data;
}

#endif //STACK_CALCULATOR_DATA_HPP
