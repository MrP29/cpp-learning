#include <iostream>

using namespace std;

int main() {
    cout << "Hello, welcome to Min's Carpet Cleaning Service\n\n";
    cout << "How many rooms would you like cleaned? ";

    int number_of_rooms {0};
    cin >> number_of_rooms;

    const double price_per_room {30};
    const double sales_tax {0.06};
    const int estimate_expiry {30};

    cout << "\nEstimate for carpet cleaning service" << endl;
    cout << "Number of rooms: " << number_of_rooms << endl;
    cout << "Price per room: $" << price_per_room << endl;

    const double cost {number_of_rooms * price_per_room};
    cout << "Cost: $" << cost << endl;

    const double tax {cost * sales_tax};
    cout << "Tax: $" << tax << endl;
    cout << "==============================" << endl;

    const double total_estimate = cost + tax;
    cout << "Total estimate: $" << total_estimate << endl;
    cout << "This estimate is valid for " << estimate_expiry << " days" << endl;

    return 0;
}