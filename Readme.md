# CPU Scheduling Algorithm Comparator (C++)

This project is a C++ console application that calculates and compares various CPU scheduling algorithms. It allows users to input a set of processes with their arrival and burst times, and then see the results of different scheduling algorithms, including First-Come, First-Serve (FCFS), Shortest Job First (SJF - Non-Preemptive), and Round Robin (RR). The tool also provides a recommendation for the best algorithm for a given workload based on the lowest average waiting time.

## Features

*   Compare Algorithms: Select and compare two different scheduling algorithms side-by-side.
*   Dynamic Process Input: Input any number of processes via the console.
*   Algorithms Supported:
    *   FCFS (First-Come, First-Serve)
    *   SJF (Shortest Job First - Non-Preemptive)
    *   Round Robin (with adjustable Time Quantum)
    *   *Note: Code includes logic for these algorithms.*
*   Detailed Results: Displays a table with Completion Time (CT), Turnaround Time (TAT), and Waiting Time (WT) for each process.
*   Recommendation Engine: Recommends the best algorithm based on the lowest average waiting time.

## File Structure

*   CPU_SHEDULING_ALGORITHM CPU_SCHEDULING.cpp: The main C++ source file containing the logic for scheduling algorithms and user interface.

## How to Compile and Run

### Prerequisites
*   A C++ compiler (e.g., G++)

### Compilation
Run the following command in your terminal to compile the code:
`ash
g++ "CPU_SHEDULING_ALGORITHM CPU_SCHEDULING.cpp" -o cpu_scheduler
`

### Usage
1.  Run the executable:
    ` ash
    ./cpu_scheduler
    `
2.  Enter the number of processes.
3.  For each process, enter the Arrival Time and Burst Time.
4.  Select two algorithms to compare from the menu:
    *   1: FCFS
    *   2: SJF
    *   3: Round Robin
5.  If Round Robin is selected, enter the Time Quantum.
6.  The program will display the schedule tables and a final recommendation.

## Code Overview

The application uses a \Process\ structure to store process details:
`cpp
struct Process {
    int id;     // Process ID
    int at;     // Arrival Time
    int bt;     // Burst Time
    int ct;     // Completion Time
    int tat;    // Turnaround Time
    int wt;     // Waiting Time
    int remaining; // Remaining Burst Time (for RR)
};
`

Key functions:
*   \solveFCFS\: Implements First-Come, First-Serve logic.
*   \solveSJF\: Implements Non-Preemptive Shortest Job First logic.
*   \solveRR\: Implements Round Robin logic with a time quantum.
*   \printTable\: specific helper to display formatted results.