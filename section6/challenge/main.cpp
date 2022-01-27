#include <iostream>

using namespace std;

int main() {
    cout << "Hello, welcome to Min's Carpet Cleaning Service\n\n";

    int number_of_small_rooms {0};
    cout << "How many small rooms would you like cleaned? ";
    cin >> number_of_small_rooms;

    int number_of_large_rooms {0};
    cout << "How many small rooms would you like cleaned? ";
    cin >> number_of_large_rooms;  

    const double price_per_small_room {25};
    const double price_per_large_room {35};

    const double sales_tax {0.06};
    const int estimate_expiry {30};

    cout << "\nEstimate for carpet cleaning service" << endl;
    cout << "Number of small rooms: " << number_of_small_rooms << endl;
    cout << "Number of large rooms: " << number_of_large_rooms << endl;
    cout << "Price per small room: $" << price_per_small_room << endl;
    cout << "Price per large room: $" << price_per_large_room << endl;

    const double cost {(number_of_small_rooms * price_per_small_room) + (number_of_large_rooms * price_per_large_room)};
    cout << "Cost: $" << cost << endl;

    const double tax {cost * sales_tax};
    cout << "Tax: $" << tax << endl;
   
    cout << "==============================" << endl;
    const double total_estimate = cost + tax;
    cout << "Total estimate: $" << total_estimate << endl;
    cout << "This estimate is valid for " << estimate_expiry << " days" << endl;

    return 0;
}