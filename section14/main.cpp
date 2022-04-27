#include <iostream>
#include "Mystring2.h"

using namespace std;

int main()
{
    cout << boolalpha << endl;
    Mystring a{"hello"};
    Mystring b{"hello"};

    cout << (a == b) << endl; // true
    cout << (a != b) << endl; // false

    b = "world";
    cout << (a == b) << endl; // false
    cout << (a != b) << endl; // true
    cout << (a < b) << endl;  // true
    cout << (a > b) << endl;  // false

    Mystring s1{"HELLO"};
    s1 = -s1;
    cout << s1 << endl; // hello

    s1 = s1 + "*****";
    cout << s1 << endl; // hello*****

    s1 += "-----";
    cout << s1 << endl; // hello*****-----

    Mystring s2{"12345"};
    s1 = s2 * 3;
    cout << s1 << endl; // 123451234512345

    Mystring s3{"abcdef"};
    s3 *= 5;
    cout << s3 << endl; // abcdefabcdefabcdef...abcdef

    Mystring s = "Hello";
    ++s;
    cout << s << endl; // HELLO

    s = -s;
    cout << s << endl; // hello

    Mystring result;
    result = ++s;
    cout << s << endl;      // HELLO
    cout << result << endl; // HELLO

    s = "Hello";
    s++;
    cout << s << endl; // HELLO

    s = -s;
    cout << s << endl; // hello
    result = s++;
    cout << s << endl;      // HELLO
    cout << result << endl; // hello

    return 0;
}