#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main() {
    cout << "Process Control Demonstration:\n";
    pid_t pid = fork();
    if (pid == 0) {
        cout << "Child process running PID: " << getpid() << endl;
        sleep(2);
        cout << "Child process finished.\n";
        exit(0);
    } else if (pid>0) {
        cout << "Parent process running. PID: " <<getpid() << endl;
        cout<< "waiting for the Child process to finish..." << endl;
        wait(nullptr);
    } else{
        cerr << "Fork Failed." <<endl;
        return 1;
    }
    cout << "Listing current processes using 'ps': \n";
    system("ps");
    cout << "demonstrating Kill: " <<getpid()<<"\n";
    kill (getpid(), SIGTERM);
}