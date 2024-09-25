#include <stdio.h>

struct Process {
    int id;
    int burstTime;
    int priority;
};

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter the burst time for process P%d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
        printf("Enter the priority for process P%d: ", i + 1);
        scanf("%d", &processes[i].priority);
    }

    // Sort processes by priority (ascending order)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    int waitingTime = 0;
    int turnaroundTime = 0;

    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        waitingTime += turnaroundTime;
        turnaroundTime += processes[i].burstTime;
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burstTime, processes[i].priority, waitingTime, turnaroundTime);
    }

    double avgWaitingTime = (double)waitingTime / n;
    double avgTurnaroundTime = (double)turnaroundTime / n;

    printf("\nAverage Waiting Time: %.2lf\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2lf\n", avgTurnaroundTime);

    return 0;
}
