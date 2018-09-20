/*
    Dummy program that creates an unreadable file. (Permission bits 0000)
*/
#include<stdio.h> 
#include<fcntl.h> 
#include<errno.h> 
#include<stdlib.h>
extern int errno; 

int main(int argc, char* argv[]) 
{      
    int fd = open(argv[1], O_RDWR | O_CREAT);
    
    return 0; 
} 