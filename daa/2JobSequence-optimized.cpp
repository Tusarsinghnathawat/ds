// nlogn time complexity because of DSU (Disjoint Set Union)
// DSU is a data structure that keeps track of a set of elements partitioned into a number of disjoint (non-overlapping) subsets
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

// Disjoint Set Union (Union-Find)
vector<int> parent;

int find(int s) {
    if (s == parent[s])
        return s;
    return parent[s] = find(parent[s]); // path compression
}

void merge(int u, int v) {
    parent[v] = u;
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);
    cout << "Enter Job ID, Deadline, Profit:\n";
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    sort(jobs.begin(), jobs.end(), compare);

    int maxDeadline = 0;
    for (auto &job : jobs)
        maxDeadline = max(maxDeadline, job.deadline);

    parent.resize(maxDeadline + 1);
    for (int i = 0; i <= maxDeadline; i++)
        parent[i] = i;

    int totalProfit = 0;
    vector<char> result;

    for (auto &job : jobs) {
        int availableSlot = find(job.deadline);
        if (availableSlot > 0) {
            merge(find(availableSlot - 1), availableSlot);
            result.push_back(job.id);
            totalProfit += job.profit;
        }
    }

    cout << "\nJob sequence for maximum profit: ";
    for (auto job : result) cout << job << " ";
    cout << "\nTotal Profit: " << totalProfit << endl;

    return 0;
}
