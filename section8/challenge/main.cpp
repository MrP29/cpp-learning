#include <iostream>

using namespace std;

int main() {
    const int dollar {100};
    const int quarter {25};
    const int dime {10};
    const int nickel {5};

    cout << "Enter an amount in cents : ";
    int change_amount {0};
    cin >> change_amount;

    cout << "You can provide change for this change as follows:" << endl;
    
    const int number_of_dollars = change_amount / dollar;
    change_amount %= dollar;
    cout << "dollars  : " << number_of_dollars << endl;

    const int number_of_quarters = change_amount / quarter;
    change_amount %= quarter;
    cout << "quarters : " << number_of_quarters << endl;

    const int number_of_dimes = change_amount / dime;
    change_amount %= dime;
    cout << "dimes    : " << number_of_dimes << endl;

    const int number_of_nickels = change_amount / nickel;
    change_amount %= nickel;
    cout << "nickels  : " << number_of_nickels << endl;

    cout << "pennies  : " << change_amount << endl;

    return 0;
}