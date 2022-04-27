#include <iostream>
#include <cstring>
#include "Mystring2.h"

// No-arg constructor
Mystring::Mystring() : str(nullptr)
{
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) : str(nullptr)
{
    if (s == nullptr)
    {
        str = new char[1];
        *str = '\0';
    }
    else
    {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
}

// Copy constructor
Mystring::Mystring(const Mystring &sourse) : str(nullptr)
{
    str = new char[strlen(sourse.str) + 1];
    strcpy(str, sourse.str);
}

// Move constructor
Mystring::Mystring(Mystring &&source) : str(source.str)
{
    source.str = nullptr;
}

// Destructor
Mystring::~Mystring()
{
    delete[] str;
}

// Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    delete[] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Move assignment
Mystring &Mystring::operator=(Mystring &&rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    delete[] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

// Display method
void Mystring::display() const
{
    std::cout << str << " : " << get_length() << std::endl;
}

int Mystring::get_length() const
{
    return strlen(str);
}

const char *Mystring::get_str() const
{
    return str;
}

std::ostream &operator<<(std::ostream &os, const Mystring &obj)
{
    os << obj.str;
    return os;
}

std::istream &operator>>(std::istream &is, Mystring &obj)
{
    char *buff = new char[1000];
    is >> buff;
    obj = Mystring{buff};
    delete[] buff;
    return is;
}

Mystring operator-(const Mystring &obj)
{
    /*
    for(size_t i = 0; i < std::strlen(obj.str); i++) {
        obj.str[i] = tolower(obj.str[i]);
    }
    return obj;
    */

    char *buff = new char[std::strlen(obj.str) + 1];
    std::strcpy(buff, obj.str);
    for (size_t i = 0; i < std::strlen(buff); i++)
    {
        buff[i] = std::tolower(buff[i]);
    }
    Mystring temp{buff};
    delete[] buff;
    return temp;
}

Mystring operator+(const Mystring &lhs, const Mystring &rhs)
{
    char *buff = new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);
    Mystring temp{buff};
    delete[] buff;
    return temp;
}

bool operator==(const Mystring &lhs, const Mystring &rhs)
{
    return std::strcmp(lhs.str, rhs.str) == 0;
}

bool operator!=(const Mystring &lhs, const Mystring &rhs)
{
    return std::strcmp(lhs.str, rhs.str) != 0;
}

bool operator<(const Mystring &lhs, const Mystring &rhs)
{
    return std::strcmp(lhs.str, rhs.str) < 0;
}

bool operator>(const Mystring &lhs, const Mystring &rhs)
{
    return std::strcmp(lhs.str, rhs.str) > 0;
}

Mystring &operator+=(Mystring &lhs, const Mystring &rhs)
{
    lhs = lhs + rhs;
    return lhs;
}

Mystring operator*(const Mystring &lhs, int n)
{
    Mystring temp;
    for (int i = 0; i < n; i++)
    {
        temp = temp + lhs.str;
    }
    return temp;
}

Mystring &operator*=(Mystring &lhs, int n)
{
    lhs = lhs * n;
    return lhs;
}

Mystring &operator++(Mystring &obj) // pre-increment - return & instead of value
{
    for (size_t i = 0; i < std::strlen(obj.str); i++)
    {
        obj.str[i] = std::toupper(obj.str[i]);
    }
    return obj;
}

Mystring operator++(Mystring &obj, int) // post-increment
{
    Mystring temp(obj);
    //operator++(obj);
    ++obj;
    return temp;
}