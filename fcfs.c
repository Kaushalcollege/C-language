#include <stdio.h>

void findWaitingTime(int processes[], int n, int burst_time[], int waiting_time[]) {
    waiting_time[0] = 0; // First process has no waiting time

    // Calculating waiting time for each process
    for (int i = 1; i < n; i++) {
        waiting_time[i] = burst_time[i - 1] + waiting_time[i - 1];
    }
}

void findTurnAroundTime(int processes[], int n, int burst_time[], int waiting_time[], int turn_around_time[]) {
    // Calculating turnaround time for each process
    for (int i = 0; i < n; i++) {
        turn_around_time[i] = burst_time[i] + waiting_time[i];
    }
}

void findAverageTime(int processes[], int n, int burst_time[]) {
    int waiting_time[n], turn_around_time[n], total_waiting_time = 0, total_turnaround_time = 0;

    // Function to find waiting time of all processes
    findWaitingTime(processes, n, burst_time, waiting_time);

    // Function to find turnaround time for all processes
    findTurnAroundTime(processes, n, burst_time, waiting_time, turn_around_time);

    // Display processes with corresponding burst time, waiting time, and turnaround time
    printf("Processes\tBurst time\tWaiting time\tTurn around time\n");

    // Calculate total waiting time and total turnaround time
    for (int i = 0; i < n; i++) {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turn_around_time[i];
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], waiting_time[i], turn_around_time[i]);
    }

    printf("Average waiting time = %.2f\n", (float)total_waiting_time / n);
    printf("Average turnaround time = %.2f\n", (float)total_turnaround_time / n);
}

int main() {
    int processes[] = {1, 2, 3};
    int n = sizeof(processes) / sizeof(processes[0]);

    int burst_time[5];// Burst time of processes
    for (int i = 0; i< n; i++)
	{
		scanf("%d", &burst_time[i]);
	}
    findAverageTime(processes, n, burst_time);

    return 0;
}

