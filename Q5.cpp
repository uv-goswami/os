#include <iostream> 
#include <fstream> 
#include <string> 
using namespace std; 
void get_memory_info() { 
    ifstream meminfo("/proc/meminfo"); 
    string line; 
    if (!meminfo.is_open()) { 
        cerr << "Failed to open /proc/meminfo" << endl; 
        exit(1);} 
    cout << "\nMemory Information:\n"; 
    while (getline(meminfo, line)) { 
        if (line.find("MemTotal") != string::npos) { 
            cout << line << endl;} 
        if (line.find("MemFree") != string::npos) { 
            cout << line << endl; } 
        if (line.find("MemAvailable") != string::npos) { 
            cout << line << endl;} 
        if (line.find("Buffers") != string::npos) { 
            cout << line << endl; } 
        if (line.find("Cached") != string::npos) { 
            cout << line << endl;} 
        if (line.find("SwapTotal") != string::npos) { 
            cout << line << endl; } 
        if (line.find("SwapFree") != string::npos) { 
            cout << line << endl;}} 
    meminfo.close();} 
int main() { 
    cout << "Linux Kernel Memory Information:\n"; 
    get_memory_info(); 
    return 0;}