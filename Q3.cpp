#include <iostream> 
#include <unistd.h> 
#include <sys/wait.h> 
using namespace std; 

void execute_same_program_same_code() { 
    cout << "Executing the same program with same code.\n";} 
void execute_same_program_different_code() { 
    cout << "Parent is executing its task.\n"; 
    execlp("pwd", "pwd",nullptr); 
    perror("exec failed");} 

int main() { 
    pid_t pid = fork(); 
    if (pid == -1) { 
        cerr << "Fork failed!\n"; 
        return 1;} 
    if (pid == 0) { 
        cout << "Child process (PID: " << getpid() << ") started.\n"; 
        execute_same_program_same_code(); 
        execute_same_program_different_code(); 
    } else { 
        cout << "Parent process (PID: " << getpid() << ") started.\n"; 
        execute_same_program_same_code(); 
        cout << "Parent is waiting for child to finish...\n"; 
        wait(NULL);  
        cout << "Child has finished. Parent is now terminating.\n";} 
    return 0;} 