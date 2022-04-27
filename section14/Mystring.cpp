#include <iostream>
#include <cstring>
#include "Mystring.h"

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

bool Mystring::operator==(const Mystring &rhs) const
{
    return std::strcmp(str, rhs.str) == 0;
}

bool Mystring::operator!=(const Mystring &rhs) const
{
    return std::strcmp(str, rhs.str) != 0;
}

bool Mystring::operator<(const Mystring &rhs) const
{
    return std::strcmp(str, rhs.str) < 0;
}

bool Mystring::operator>(const Mystring &rhs) const
{
    return std::strcmp(str, rhs.str) > 0;
}

// Make lowercase
Mystring Mystring::operator-() const
{
    char *buff = new char[std::strlen(str) + 1];
    strcpy(buff, str);
    for (size_t i = 0; i < std::strlen(buff); i++)
    {
        buff[i] = std::tolower(buff[i]);
    }
    Mystring temp{buff};
    delete[] buff;
    return temp;
}

// Concatenate
Mystring Mystring::operator+(const Mystring &rhs) const
{
    char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
    strcpy(buff, str);
    strcat(buff, rhs.str);
    Mystring temp{buff};
    delete[] buff;
    return temp;
}

// Concat and assign
Mystring &Mystring::operator+=(const Mystring &rhs)
{
    /*
    char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
    strcpy(buff, str);
    strcat(buff, rhs.str);

    delete [] str;
    str = new char[std::strlen(buff)];
    strcpy(str, buff);
    delete [] buff;
    */
    *this = *this + rhs;
    return *this;
}

// Repeat
Mystring Mystring::operator*(int n) const
{
    /*
    char *buff = new char[std::strlen(str) * rhs + 1];

    for(size_t i = 0; i < rhs; i++) {
        strcat(buff, str);
    }
    Mystring temp {buff};
    delete [] buff;
    */
    Mystring temp;
    for (size_t i = 0; i < n; i++)
    {
        temp = temp + *this;
    }
    return temp;
}

// Repeat and assign
Mystring &Mystring::operator*=(int n)
{
    /*
    char *buff = new char[std::strlen(str) * rhs + 1];

    for (size_t i = 0; i < rhs; i++)
    {
        strcat(buff, str);
    }
    delete[] str;
    str = new char[std::strlen(buff)];
    strcpy(str, buff);
    delete[] buff;
    */
    *this = *this * n;
    return *this;
}

// Pre-increment - make the string upper-case
Mystring &Mystring::operator++()
{
    /*
    char *buff = new char[std::strlen(str) + 1];
    strcpy(buff, str);
    for (size_t i = 0; i < std::strlen(str); i++)
    {
        buff[i] = toupper(buff[i]);
    }
    Mystring temp{buff};
    strcpy(str, buff);
    delete[] buff;
    */
    for (size_t i = 0; i < std::strlen(str); i++)
    {
        str[i] = std::toupper(str[i]);
    }
    return *this;
}

// Post-increment - make the string upper-case
Mystring Mystring::operator++(int)
{
    /*
    Mystring temp{str};

    char *buff = new char[std::strlen(str) + 1];
    strcpy(buff, str);
    for (size_t i = 0; i < std::strlen(str); i++)
    {
        buff[i] = toupper(buff[i]);
    }
    strcpy(str, buff);
    delete[] buff;
    */
    Mystring temp(*this);
    operator++();
    return temp;
}