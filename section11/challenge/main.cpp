#include <iostream>
#include <vector>

using namespace std;

void display_menu();
char get_selection();
void handle_display(const vector<int> &v);
void handle_add(vector<int> &v);
void handle_mean(const vector<int> &v);
void handle_smallest(const vector<int> &v);
void handle_largest(const vector<int> &v);
void handle_find(const vector<int> &v);
void handle_quit();
void handle_unknown();

void display_list(const vector<int> &v);
double calculate_mean(const vector<int> &v);
int get_smallest(const vector<int> &v);
int get_largest(const vector<int> &v);
bool find(const vector<int> &v, int target);

int main() {
    char selection {};
    vector<int> numbers;

    do {
        display_menu();
        selection = get_selection();
        switch(selection) {
            case 'P':
                handle_display(numbers);
                break;
            case 'A':
                handle_add(numbers);
                break;
            case 'M':
                handle_mean(numbers);
                break;
            case 'S':
                handle_smallest(numbers);
                break;
            case 'L':
                handle_largest(numbers);
                break;
            case 'F':
                handle_find(numbers);
                break;
            case 'Q':
                handle_quit();
                break;
            default:
                handle_unknown();
        }
    } while(selection != 'Q');
}

void display_menu() {
    cout << "\nP - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "F - Find a number" << endl;
    cout << "Q - Quit" << endl;
    cout << "\nEnter your choice: ";
}

char get_selection() {
    char selection {};
    cin >> selection;
    return toupper(selection);
}

void handle_display(const vector<int> &v) {
    if(v.size() == 0) {
        cout << "[] - the numbers is empty" << endl;
    } else {
        display_list(v);
    }
}

void handle_add(vector<int> &v) {
    int num_to_add {};
    cout << "Enter an integer to add to the numbers: ";
    cin >> num_to_add;

    v.push_back(num_to_add);
    cout << num_to_add << " added" << endl;
}

void handle_mean(const vector<int> &v) {
    if(v.size() == 0) {
        cout << "Unable to calculate the mean - no data" << endl;
    } else {
        cout << "The mean is : " << calculate_mean(v) << endl;
    }
}

void handle_smallest(const vector<int> &v) {
    if(v.size() == 0) {
        cout << "Unable to determine the smallest - list is empty" << endl;
    } else {
        cout << "The smallest number is " << get_smallest(v) << endl;
    }
}

void handle_largest(const vector<int> &v) {
    if(v.size() == 0) {
        cout << "Unable to determine the largest - list is empty" << endl;
    } else {
        cout << "The largest number is " << get_largest(v) << endl;
    }
}

void handle_find(const vector<int> &v) {
    int target {};
    cout << "Enter the number to find: ";
    cin >> target;

    if(find(v, target)) {
        cout << target << " was found" << endl;
    } else {
        cout << target << " was not found" << endl;
    }
}

void display_list(const vector<int> &v) {
    cout << "[ ";
    for(auto num: v) {
        cout << num << " ";
    }
    cout << "]" << endl;
}

double calculate_mean(const vector<int> &v) {
    int sum {0};
    for(auto num : v) {
        sum += num;
    }

    return static_cast<double> (sum) / v.size();
}

int get_smallest(const vector<int> &v) {
    int smallest {v.at(0)};
    for(auto num : v) {
        if(smallest > num) {
            smallest = num;
        }
    }
    return smallest;
}

int get_largest(const vector<int> &v) {
    int largest {v.at(0)};
    for(auto num : v) {
        if(largest < num) {
            largest = num;
        }
    }
    return largest;
}

bool find(const vector<int> &v, const int target) {
    for(auto num: v) {
        if(num == target) {
            return true;
        }
    }
    return false;
}

void handle_quit() {
    cout << "Goodbye" << endl;
}

void handle_unknown() {
    cout << "Unknown selection, please try again" << endl;
}