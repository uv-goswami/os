#include <iostream> 
#include <fcntl.h>   
#include <unistd.h>  
#include <sys/types.h>  
#include <sys/stat.h>  
using namespace std; 
void copy_file(const char* source, const char* destination) { 
    int source_fd = open(source, O_RDONLY); 
    if (source_fd == -1) { 
        perror("Failed to open source file"); 
        exit(1);} 
    int dest_fd = open(destination, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR); 
    if (dest_fd == -1) { 
        perror("Failed to open destination file"); 
        close(source_fd); 
        exit(1);} 
    char buffer[1024]; 
    ssize_t bytes_read, bytes_written; 
    while ((bytes_read = read(source_fd, buffer, sizeof(buffer))) > 0) { 
        bytes_written = write(dest_fd, buffer, bytes_read); 
        if (bytes_written != bytes_read) { 
            perror("Error writing to destination file"); 
            close(source_fd); 
            close(dest_fd); 
            exit(1);}} 
    if (bytes_read == -1) { 
        perror("Error reading from source file");} 
    close(source_fd); 
    close(dest_fd); 
    cout << "File copied successfully from " << source << " to " << destination << endl;} 
int main() { 
    const char* source = "source.txt";  
    const char* destination = "destination.txt"; 
    copy_file(source, destination); 
    return 0;} 