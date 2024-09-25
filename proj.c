#include <stdio.h>
struct Process {
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};
int main() {
    int n; // Number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process processes[n];
    for (int i = 0; i < n; i++) {
        printf("Enter priority and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].priority, &processes[i].burst_time);
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }
    int current_time = 0; // Current time
    float total_waiting_time = 0;
    float total_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        int highest_priority = -1;
        for (int j = 0; j < n; j++) {
            if (processes[j].burst_time > 0 && (highest_priority == -1 || processes[j].priority < processes[highest_priority].priority)) {
                highest_priority = j;
            }
        }
        processes[highest_priority].burst_time--;
        current_time++;
        for (int j = 0; j < n; j++) {
            if (j != highest_priority && processes[j].burst_time > 0) {
                processes[j].waiting_time++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + 1;
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }
    printf("\nProcess\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, processes[i].priority, 1, processes[i].waiting_time, processes[i].turnaround_time);
    }
    printf("\nAverage Waiting Time: %.2f\n", total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);
    return 0;
}