#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

void display(string name_of_process[],int burst_time[],int arrival_time[],int number_of_processes,int waiting_time[],int turnaround_time[]){
    double total_waiting_time = 0;
    double total_turnaround_time = 0;

    cout << "Name Of Process\tBurst Time\tArrival Time\tWaiting Time\tTurnAround Time" << endl;
    for (int num = 0; num < number_of_processes; num++) {
        total_waiting_time += waiting_time[num];
        total_turnaround_time += turnaround_time[num];
        cout << name_of_process[num] << "\t\t" << burst_time[num] << "\t\t" << arrival_time[num];
        cout<< "\t\t" << waiting_time[num];
        cout << "\t\t" << turnaround_time[num] << endl;
    }
    cout << "\nAverage Waiting Time is: " << total_waiting_time/number_of_processes;
    cout << "\nAverage TurnAround Time is: ";
    cout<< total_turnaround_time / number_of_processes << endl;
}

void shortest_remaining_time_first(string name_of_process[], int number_of_processes, int burst_time[], int arrival_time[]) {
    int waiting_time[number_of_processes];
    int turnaround_time[number_of_processes];
    int remaining_time[number_of_processes];
    copy(burst_time, burst_time + number_of_processes, remaining_time);

    int clock = 0;
    int completed = 0;
    float min_burst = numeric_limits<float>::infinity();
    int shortest = -1;
    bool finished = false;

    while (completed != number_of_processes) {
        for (int num = 0; num < number_of_processes; num++) {
            if (arrival_time[num] <= clock && remaining_time[num] < min_burst && remaining_time[num] > 0) {
                min_burst = remaining_time[num];
                shortest = num;
                finished = true;
            }
        }

        if (!finished) {
            clock++;
            continue;
        }

        remaining_time[shortest]--;
        min_burst = remaining_time[shortest];
        if (min_burst == 0) {
            min_burst = numeric_limits<float>::infinity();
        }

        if (remaining_time[shortest] == 0) {
            completed++;
            finished = false;
            int finish_time = clock + 1;
            waiting_time[shortest] = finish_time - burst_time[shortest] - arrival_time[shortest];
            turnaround_time[shortest] = finish_time - arrival_time[shortest];

            if (waiting_time[shortest] < 0) {
                waiting_time[shortest] = 0;
            }
        }

        clock++;
    }

    display(name_of_process, burst_time, arrival_time, number_of_processes, waiting_time, turnaround_time);
}

int main() {
    int number_of_processes;
    cout << "Enter the number of processes: ";
    cin >> number_of_processes;
    string name_of_process[number_of_processes];
    int burst_time[number_of_processes];
    int arrival_time[number_of_processes];
    for (int i = 0; i < number_of_processes; i++) {
        cout << "Enter Name of Process: ";
        cin >> name_of_process[i];
        cout << "Enter Burst Time of Process " << name_of_process[i] << ": ";
        cin >> burst_time[i];
        cout << "Enter Arrival Time of Process " << name_of_process[i] << ": ";
        cin >> arrival_time[i];
    }

    shortest_remaining_time_first(name_of_process, number_of_processes, burst_time, arrival_time);
    return 0;
}
