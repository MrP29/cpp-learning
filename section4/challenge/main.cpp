#include <iostream>

using namespace std;

int main() {
    int fav_num = -1;

    cout << "Enter your favorite number between 1 and 100: ";
    cin >> fav_num;
    
    cout << "Amazing!! That's my favorite number too!" << endl;
    cout << "No really!!, " << fav_num << " is my favorite number!" << endl;

    return 0;
}