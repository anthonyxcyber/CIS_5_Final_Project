Code:
#include <iostream>
#include <string>
using namespace std;

struct Villain {
    string name;
    int power;
    int intelligence;
    int chaos;
    int threat; // 0=LOW, 1=MEDIUM, 2=HIGH
};

int calcScore(const Villain& v) {
    return v.power + v.intelligence + v.chaos;
}

void classifyThreat(Villain& v) {
    int score = calcScore(v);

    if (score >= 220) v.threat = 2;
    else if (score >= 150) v.threat = 1;
    else v.threat = 0;
}

void inputVillain(Villain* v) {
    cout << "Villain name: ";
    getline(cin, v->name);

    cout << "Power (0-100): ";
    cin >> v->power;

    cout << "Intelligence (0-100): ";
    cin >> v->intelligence;

    cout << "Chaos (0-100): ";
    cin >> v->chaos;

    cin.ignore(1000, '\n');

    classifyThreat(*v);
}

void printVillain(const Villain& v) {
    cout << "Name: " << v.name << "\n";
    cout << "Power: " << v.power << "\n";
    cout << "Intelligence: " << v.intelligence << "\n";
    cout << "Chaos: " << v.chaos << "\n";
    cout << "Score: " << calcScore(v) << "\n";
    cout << "Threat: ";
    if (v.threat == 2) cout << "HIGH\n";
    else if (v.threat == 1) cout << "MEDIUM\n";
    else cout << "LOW\n";
    cout << "-------------------------\n";
}

void countThreats(Villain arr[], int n, int& low, int& med, int& high) {
    low = 0; med = 0; high = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].threat == 2) high++;
        else if (arr[i].threat == 1) med++;
        else low++;
    }
}

int main() {
    const int MAX = 5;
    Villain villains[MAX];
    int count = 0;
    int choice = 0;

    do {
        cout << "\n=== S.H.I.E.L.D. Threat Database ===\n";
        cout << "1) Add villains (up to 5)\n";
        cout << "2) Show all villains\n";
        cout << "3) Threat summary\n";
        cout << "4) Quit\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore(1000, '\n');

        if (choice == 1) {
            if (count >= MAX) {
                cout << "Database full.\n";
            }
            else {
                while (count < MAX) {
                    cout << "\nEnter villain #" << (count + 1) << "\n";
                    inputVillain(&villains[count]);
                    count++;

                    char more;
                    cout << "Add another? (y/n): ";
                    cin >> more;
                    cin.ignore(1000, '\n');

                    if (more != 'y' && more != 'Y') break;
                }
            }
        }
        else if (choice == 2) {
            if (count == 0) {
                cout << "No villains saved.\n";
            }
            else {
                for (int i = 0; i < count; i++) {
                    printVillain(villains[i]);
                }
            }
        }
        else if (choice == 3) {
            if (count == 0) {
                cout << "No villains saved.\n";
            }
            else {
                int low, med, high;
                countThreats(villains, count, low, med, high);
                cout << "LOW: " << low << "\n";
                cout << "MEDIUM: " << med << "\n";
                cout << "HIGH: " << high << "\n";
            }
        }
        else if (choice == 4) {
            cout << "Exiting.\n";
        }
        else {
            cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}
