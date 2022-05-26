#include <iostream>
using namespace std;

int main()
{
    int conveyor_count; int worckers_count; int choise; int delta_count;
    cout << "Enter the number of conveys:\n";
    cin >> conveyor_count;
    cout << "Enter the workers:\n"; cin >> worckers_count;
    if (conveyor_count > worckers_count)
    {
        cout << "The work is going very slowly, do you want to add workers?\n";
        cin >> choise;
        switch (choise) {
        case 1:
            cout << "Enter the number of new workers\n";
            cin >> delta_count;
            worckers_count += delta_count;
            if (delta_count == 0) {
                cout << "You haven't changed anything";
            }
            else {
                cout << "There are more workers:" << worckers_count << "\nNow the work has accelerated";
            }
            break;
        case 2:
            cout << "You haven't changed anything";
            break;
        default:
            cout << "Nothing";
            break;
        }
    }
    if (worckers_count > conveyor_count) {
        cout << "There are a lot of workers, but who cares, do you want more conveys?\n";
        cin >> choise;
        switch (choise) {
        case 1:
            cout << "Enter the number of conveys\n";
            cin >> delta_count;
            conveyor_count += delta_count;
            if (delta_count == 0) {
                cout << "You haven't changed anything";
            }
            else {
                cout << "There are more conveys:" << conveyor_count << "\nNow the work has accelerated";
            }
            break;
        case 2:
            cout << "You haven't changed anything";
            break;
        default:
            cout << "Nothing";
            break;
        }
    }
    else {
        cout << "Stability";
    }
}