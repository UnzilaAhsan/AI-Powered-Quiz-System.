#include "MyString.h"
#include <cstring>
using namespace std;

MyString::MyString() : data(nullptr), length(0) {}

MyString::MyString(const char* str) {
    length = 0;
    while (str[length] != '\0') length++;
    data = new char[length + 1];
    for (int i = 0; i <= length; ++i)
        data[i] = str[i];
}

MyString::MyString(const MyString& other) {
    length = other.length;
    data = new char[length + 1];
    for (int i = 0; i <= length; ++i)
        data[i] = other.data[i];
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        delete[] data;
        length = other.length;
        data = new char[length + 1];
        for (int i = 0; i <= length; ++i)
            data[i] = other.data[i];
    }
    return *this;
}

MyString::~MyString() {
    delete[] data;
}

int MyString::size() const {
    return length;
}

const char* MyString::c_str() const {
    return data;
}

char& MyString::operator[](int index) {
    return data[index];
}

const char& MyString::operator[](int index) const {
    return data[index];
}

bool MyString::operator==(const MyString& other) const {
    if (length != other.length) return false;
    for (int i = 0; i < length; ++i)
        if (data[i] != other.data[i])
            return false;
    return true;
}

bool MyString::operator!=(const MyString& other) const {
    return !(*this == other);
}

ostream& operator<<(ostream& os, const MyString& str) {
    os << str.data;
    return os;
}
