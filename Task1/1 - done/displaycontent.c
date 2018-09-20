/*
    This program takes in 1 argument. Contents will be read and 
    displayed to screen.

    To check validity of program, I have 2 files on current directory:
        1) b.txt with random text inside
        2) unreadable.txt with permission bits 0000

    Errors handled: 
        - if file 1 does not exists, error - no such file
        - if file 1 does not have read permissions, error - permission denied
*/
#include<stdio.h> 
#include<fcntl.h> 
#include<errno.h> 
#include<stdlib.h>
extern int errno; 

int main(int argc, char* argv[]) 
{      
    int fd;
    if ((fd = open(argv[1], O_RDWR)) >= 0)
    {
        // char c;
        // while (read(fd, &c, 1) == 1)
        //     putchar(c);
        printf("Error Number: %d\n", errno);  
    } else {
        printf("Error Number: %d\n", errno);  
        // print program detail "Success or failure" 
        perror("Program");            
        exit(1); 
    }
    return 0; 
} 