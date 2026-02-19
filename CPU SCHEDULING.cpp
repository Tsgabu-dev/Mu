#include <iostream>

using namespace std;

struct Process {
    int id;
    int at, bt, ct, tat, wt, remaining;
};

Process original[100];
Process tempP[100];
int n;

void resetTemp() {
    for (int i = 0; i < n; i++) {
        tempP[i] = original[i];
        tempP[i].remaining = original[i].bt;
    }
}

void printTable(const char* name, double avgWT, double avgTAT) {
    cout << "\n--- Result: " << name << " ---\n";
    cout << "PID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << tempP[i].id << "\t"
             << tempP[i].at << "\t"
             << tempP[i].bt << "\t"
             << tempP[i].ct << "\t"
             << tempP[i].tat << "\t"
             << tempP[i].wt << "\n";
    }
    cout << "Avg Waiting Time: " << avgWT << "\n";
    cout << "Avg Turnaround Time: " << avgTAT << "\n";
}

double wt1, tat1, wt2, tat2;

void solveFCFS(double &awt, double &atat) {
    resetTemp();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tempP[j].at > tempP[j + 1].at) {
                Process t = tempP[j]; tempP[j] = tempP[j+1]; tempP[j+1] = t;
            }
        }
    }
    int time = 0;
    double totalWT = 0, totalTAT = 0;
    for (int i = 0; i < n; i++) {
        if (time < tempP[i].at) time = tempP[i].at;
        tempP[i].ct = time + tempP[i].bt;
        tempP[i].tat = tempP[i].ct - tempP[i].at;
        tempP[i].wt = tempP[i].tat - tempP[i].bt;
        totalWT += tempP[i].wt;
        totalTAT += tempP[i].tat;
        time = tempP[i].ct;
    }
    awt = totalWT / n;
    atat = totalTAT / n;
    printTable("FCFS", awt, atat);
}

void solveSJF(double &awt, double &atat) {
    resetTemp();
    bool done[100] = {false};
    int completed = 0, time = 0;
    double totalWT = 0, totalTAT = 0;
    while (completed < n) {
        int idx = -1;
        int minBT = 10000;
        for (int i = 0; i < n; i++) {
            if (!done[i] && tempP[i].at <= time && tempP[i].bt < minBT) {
                minBT = tempP[i].bt;
                idx = i;
            }
        }
        if (idx == -1) time++;
        else {
            tempP[idx].ct = time + tempP[idx].bt;
            tempP[idx].tat = tempP[idx].ct - tempP[idx].at;
            tempP[idx].wt = tempP[idx].tat - tempP[idx].bt;
            totalWT += tempP[idx].wt;
            totalTAT += tempP[idx].tat;
            time = tempP[idx].ct;
            done[idx] = true;
            completed++;
        }
    }
    awt = totalWT / n;
    atat = totalTAT / n;
    printTable("SJF (Non-Preemptive)", awt, atat);
}

void solveRR(int tq, double &awt, double &atat) {
    resetTemp();
    int time = 0, completed = 0;
    double totalWT = 0, totalTAT = 0;
    int q[2000], head = 0, tail = 0; 
    bool inQueue[100] = {false};

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tempP[j].at > tempP[j + 1].at) {
                Process t = tempP[j]; tempP[j] = tempP[j+1]; tempP[j+1] = t;
            }
        }
    }

    time = tempP[0].at;
    q[tail++] = 0;
    inQueue[0] = true;

    while (head < tail) {
        int i = q[head++];
        int execute = (tempP[i].remaining > tq) ? tq : tempP[i].remaining;
        time += execute;
        tempP[i].remaining -= execute;

        for (int j = 0; j < n; j++) {
            if (!inQueue[j] && tempP[j].at <= time && tempP[j].remaining > 0) {
                q[tail++] = j;
                inQueue[j] = true;
            }
        }

        if (tempP[i].remaining > 0) {
            q[tail++] = i;
        } else {
            tempP[i].ct = time;
            tempP[i].tat = tempP[i].ct - tempP[i].at;
            tempP[i].wt = tempP[i].tat - tempP[i].bt;
            totalWT += tempP[i].wt;
            totalTAT += tempP[i].tat;
            completed++;
        }
    }
    awt = totalWT / n;
    atat = totalTAT / n;
    printTable("Round Robin", awt, atat);
}

int main() {
    cout << "--- CPU SCHEDULER COMPARISON ---\n";
    cout << "Enter number of processes: "; cin >> n;

    for (int i = 0; i < n; i++) {
        original[i].id = i + 1;
        cout << "\nProcess P" << i + 1 << ":\n";
        cout << "  Enter Arrival Time: "; cin >> original[i].at;
        cout << "  Enter Burst Time: "; cin >> original[i].bt;
    }

    int c1, c2;
    cout << "\nALGORITHMS:\n1. FCFS\n2. SJF\n3. Round Robin\n";
    cout << "Select Algorithm 1: "; cin >> c1;
    cout << "Select Algorithm 2: "; cin >> c2;

    int tq = 0;
    if (c1 == 3 || c2 == 3) {
        cout << "\nEnter Time Quantum for RR: "; cin >> tq;
    }

    if (c1 == 1) solveFCFS(wt1, tat1);
    else if (c1 == 2) solveSJF(wt1, tat1);
    else solveRR(tq, wt1, tat1);

    if (c2 == 1) solveFCFS(wt2, tat2);
    else if (c2 == 2) solveSJF(wt2, tat2);
    else solveRR(tq, wt2, tat2);

    cout << "\n========================================\n";
    cout << "             FINAL VERDICT              \n";
    cout << "========================================\n";
    
    if (wt1 < wt2) {
        cout << "RECOMMENDATION: Algorithm 1 is better.\n";
        cout << "REASON: Average Waiting Time is lower by " << (wt2 - wt1) << ".\n";
    } else if (wt2 < wt1) {
        cout << "RECOMMENDATION: Algorithm 2 is better.\n";
        cout << "REASON: Average Waiting Time is lower by " << (wt1 - wt2) << ".\n";
    } else {
        cout << "Both algorithms perform equally.\n";
    }
    cout << "========================================\n";

    return 0;
}
    