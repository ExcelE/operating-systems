/*
    This program checks if the file exists. If it doesn't,
    the file will be created.
*/
#include<stdio.h> 
#include<fcntl.h> 
#include<errno.h> 
#include<stdlib.h>
extern int errno; 
int main(int argc, char* argv[]) 
{      

    int fd = open(argv[1], O_RDONLY | O_CREAT);  
      
    if (fd ==-1) 
    { 
        // print which type of error have in a code 
        printf("Error Number % d\n", errno);  
          
        // print program detail "Success or failure" 
        perror("Program");            
        exit(1);      
    } 
    printf("Created successfully!");
    return 0; 
} 
