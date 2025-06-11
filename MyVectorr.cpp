#include "MyVector.h"
#include <iostream>
using namespace std;

template <typename T>
MyVector<T>::MyVector() : arr(new T[1]), capacity(1), count(0) {}

template <typename T>
MyVector<T>::~MyVector() {
    delete[] arr;
}

template <typename T>
void MyVector<T>::resize() {
    capacity *= 2;
    T* newArr = new T[capacity];
    for (int i = 0; i < count; ++i)
        newArr[i] = arr[i];
    delete[] arr;
    arr = newArr;
}

template <typename T>
void MyVector<T>::push_back(const T& val) {
    if (count == capacity) resize();
    arr[count++] = val;
}

template <typename T>
void MyVector<T>::pop_back() {
    if (count > 0) count--;
}

template <typename T>
int MyVector<T>::size() const {
    return count;
}

template <typename T>
T& MyVector<T>::operator[](int index) {
    if (index < 0 || index >= count) {
        cout << "Index out of range\n";
        return arr[0]; 
    }
    return arr[index];
}

template <typename T>
const T& MyVector<T>::operator[](int index) const {
    if (index < 0 || index >= count) {
        cout << "Index out of range\n";
        return arr[0];
    }
    return arr[index];
}

template class MyVector<int>;
template class MyVector<char>;
template class MyVector<double>;
template class MyVector<bool>;
template class MyVector<float>;

