#ifndef MYVECTOR_H
#define MYVECTOR_H
using namespace std;

template <typename T>
class MyVector {
private:
    T* arr;
    int capacity;
    int count;
    void resize();
public:
    MyVector();
    ~MyVector();

    void push_back(const T& val);
    void pop_back();
    int size() const;
    T& operator[](int index);
    const T& operator[](int index) const;
};

#endif
