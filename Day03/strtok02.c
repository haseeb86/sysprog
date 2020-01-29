
// C program to demonstrate working of strtok_r() 
// by splitting string based on space character. 
#include <stdio.h> 
#include <string.h> 
  
int main() 
{ 
    char str[] = "Welcome to system programming"; 
    char* token; 
    char* rest = str; 
  
    while ((token = strtok_r(rest, " ", &rest))) 
        printf("%s\n", token); 
  
    return (0); 
} 

