#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
    friend std::ostream &operator<<(std::ostream &os, const Mystring &obj);
    friend std::istream &operator>>(std::istream &is, Mystring &obj);

private:
    char *str;

public:
    Mystring();
    Mystring(const char *s);
    Mystring(const Mystring &source);
    Mystring(Mystring &&source);
    ~Mystring();

    Mystring &operator=(const Mystring &rhs);
    Mystring &operator=(Mystring &&rhs);

    void display() const;

    int get_length() const;
    const char *get_str() const;

    // Overloaded operator member methods
    Mystring operator-() const;
    Mystring operator+(const Mystring &rhs) const;
    bool operator==(const Mystring &rhs) const;
    bool operator!=(const Mystring &rhs) const;
    bool operator<(const Mystring &rhs) const;
    bool operator>(const Mystring &rhs) const;
    Mystring &operator+=(const Mystring &rhs);
    Mystring operator*(int n) const;
    Mystring &operator*=(int n);
    Mystring &operator++();   // pre-increment - return & instead of value
    Mystring operator++(int); // post-increment
};

#endif