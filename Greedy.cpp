#include <iostream>
using namespace std;

const int INF = 9999;

// ---------- STRUCTURES ----------
struct Patient {
    int id;
    int severity;
};

struct Task {
    char id;
    int deadline;
    int profit;
};

// ---------- SELECTION SORT ----------
void patientPriority() {
    int n;
    cout << "\nEnter number of patients: ";
    cin >> n;

    Patient p[20];

    for(int i = 0; i < n; i++) {
        cout << "Enter Patient ID: ";
        cin >> p[i].id;

        cout << "Enter Severity (smaller = more critical): ";
        cin >> p[i].severity;
    }

    for(int i = 0; i < n - 1; i++) {
        int min = i;

        for(int j = i + 1; j < n; j++) {
            if(p[j].severity < p[min].severity) {
                min = j;
            }
        }

        swap(p[i], p[min]);
    }

    cout << "\nTreatment Priority:\n";
    for(int i = 0; i < n; i++) {
        cout << "Patient " << p[i].id
             << " Severity " << p[i].severity << endl;
    }
}

// ---------- JOB SCHEDULING ----------
void taskScheduling() {
    int n;
    cout << "\nEnter number of tasks: ";
    cin >> n;

    Task t[20];

    for(int i = 0; i < n; i++) {
        cout << "Enter Task ID: ";
        cin >> t[i].id;

        cout << "Enter Deadline: ";
        cin >> t[i].deadline;

        cout << "Enter Profit: ";
        cin >> t[i].profit;
    }

    // Sort by profit
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(t[j].profit > t[i].profit) {
                swap(t[i], t[j]);
            }
        }
    }

    int slot[20] = {0};
    char result[20];

    for(int i = 0; i < n; i++) {
        for(int j = t[i].deadline - 1; j >= 0; j--) {
            if(slot[j] == 0) {
                slot[j] = 1;
                result[j] = t[i].id;
                break;
            }
        }
    }

    cout << "\nScheduled Tasks for Maximum Profit:\n";
    for(int i = 0; i < n; i++) {
        if(slot[i]) {
            cout << result[i] << " ";
        }
    }
    cout << endl;
}

// ---------- PRIMS ----------
void prims() {
    int n;
    cout << "Enter number of offices: ";
    cin >> n;

    int cost[20][20];

    cout << "Enter cost matrix:\n";
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> cost[i][j];

            if(cost[i][j]==0)
                cost[i][j]=9999;
        }
    }

    int visited[20]={0};
    visited[0]=1;

    int edges=0,mincost=0;

    while(edges<n-1) {
        int min=9999,a,b;

        for(int i=0;i<n;i++) {
            if(visited[i]) {
                for(int j=0;j<n;j++) {
                    if(!visited[j] && cost[i][j]<min) {
                        min=cost[i][j];
                        a=i;
                        b=j;
                    }
                }
            }
        }

        cout<<"Connection: "<<a<<" -> "<<b
            <<" Cost: "<<min<<endl;

        visited[b]=1;
        mincost+=min;
        edges++;
    }

    cout<<"Minimum Cost = "<<mincost<<endl;
}


// ---------- MAIN ----------
int main() {
    int choice;

    do {
        cout << "\n===== GREEDY ALGORITHM MENU =====\n";
        cout << "1. Patient Priority System\n";
        cout << "2. Task Scheduling System\n";
        cout << "3. Minimum Cost\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                patientPriority();
                break;

            case 2:
                taskScheduling();
                break;

            case 3:
                prims();
                break;

            case 4:
                cout << "Program Ended.\n"; 
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 4);

    return 0;
}