#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    char id;        // Job ID
    int deadline;   // Deadline
    int profit;     // Profit
};

// Sort jobs by descending profit
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    Job jobs[n];
    cout << "Enter Job ID, Deadline, and Profit:\n";
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    sort(jobs, jobs + n, compare);

    // Find maximum deadline
    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;

    char schedule[maxDeadline + 1];
    bool slot[maxDeadline + 1];
    for (int i = 0; i <= maxDeadline; i++)
        slot[i] = false;

    int totalProfit = 0;

    // Schedule jobs
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (!slot[j]) {
                schedule[j] = jobs[i].id;
                slot[j] = true;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    cout << "\nJob sequence for maximum profit: ";
    for (int i = 1; i <= maxDeadline; i++) {
        if (slot[i]) cout << schedule[i] << " ";
    }
    cout << "\nTotal Profit: " << totalProfit << endl;
}
