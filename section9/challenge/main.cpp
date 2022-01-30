#include <iostream>
#include <vector>

using namespace std;

int main() {
    char selection {};
    vector<int> numbers {};
    int smallest {INT_MAX};
    int largest {INT_MIN};
    int sum {0};

    do {
        // Display menu
        cout << "\nP - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "Q - Quit" << endl;
        cout << "\nEnter your choice: ";
        cin >> selection;

        switch(selection) {
            case 'p':
            case 'P':
                if(numbers.size() == 0) {
                    cout << "[] - the numbers is empty" << endl;
                } else {
                    cout << "[ ";
                    for(auto num: numbers) {
                        cout << num << " ";
                    }
                    cout << "]" << endl;
                }
                break;
            case 'a':
            case 'A':
            {
                int num_to_add {};
                cout << "Enter an integer to add to the numbers: ";
                cin >> num_to_add;
                numbers.push_back(num_to_add);
                cout << num_to_add << " added" << endl;

                if(num_to_add < smallest) {
                    smallest = num_to_add;
                }

                if(num_to_add > largest) {
                    largest = num_to_add;
                }

                sum += num_to_add;
                break;
            }
            case 'm':
            case 'M':
            {
                if(numbers.size() == 0) {
                    cout << "Unable to calculate the mean - no data" << endl;
                } else {
                    const double mean = static_cast<double>(sum) / numbers.size();
                    cout << "The mean is : " << mean << endl;
                }
                break;
            }
            case 's':
            case 'S':
                if(numbers.size() == 0) {
                    cout << "Unable to determine the smallest - list is empty" << endl;
                } else {
                    cout << "The smallest number is " << smallest << endl;
                }
                break;
            case 'l':
            case 'L':
                if(numbers.size() == 0) {
                    cout << "Unable to determine the largest - list is empty" << endl;
                } else {
                    cout << "The largest number is " << largest << endl;
                }
                break;
            case 'q':
            case 'Q':
                cout << "Goodbye" << endl;
                break;
            default:
                cout << "Unknown selection, please try again" << endl;
        }
    } while(selection != 'q' && selection != 'Q');

    return 0;
}