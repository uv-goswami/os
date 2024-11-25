#include <iostream>
using namespace std;

void First_Come_First_Serve(string name_of_process[], int burst_time[], int number_of_processes) {
    double waiting_time = 0;
    double turnaround_time = 0;
    double total_waiting_time = 0;
    double total_turnaround_time = 0;
    cout << "Name Of Process\tBurst Time\tWaiting Time\tTurnAround Time" << endl;
    for (int i = 0; i < number_of_processes; i++) {
        turnaround_time += burst_time[i];
        total_turnaround_time += turnaround_time;
        cout << name_of_process[i] << "\t\t" << burst_time[i] << "\t\t" << waiting_time << "\t\t" << turnaround_time << endl;
        total_waiting_time += waiting_time;
        waiting_time += burst_time[i];
    }
    cout << "\nAverage Waiting Time is:: " << total_waiting_time / number_of_processes << "\nAverage TurnAround Time is::" << total_turnaround_time / number_of_processes << endl;
}

int main() {
    int number_of_processes;
    cout << "Enter the number of processes: ";
    cin >> number_of_processes;
    string name_of_process[number_of_processes];
    int burst_time[number_of_processes];
    
    for (int i = 0; i < number_of_processes; i++) {
        cout << "Enter Name of Process:: ";
        cin >> name_of_process[i];
        cout << "Enter Burst Time of Process " << name_of_process[i] << ":: ";
        cin >> burst_time[i];
    }
    
    First_Come_First_Serve(name_of_process, burst_time, number_of_processes);
    return 0;
}
