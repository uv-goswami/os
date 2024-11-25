#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>

int main() { 
printf("Kernel Version:\n"); 
system("uname -r"); 
printf("\nCPU Type:\n"); 
system("uname -m"); 
printf("\nDetailed CPU Information:\n"); 
system("lscpu"); 
return 0;
}