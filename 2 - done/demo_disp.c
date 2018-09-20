/*
    Test
    Copies content in file 1 into a buffer.
*/
#include<stdio.h> 
#include<fcntl.h> 
#include<errno.h>
#include<stdlib.h>
int main(int argc, char* argv[]) 
{ 
    char c;
    char* buff; int i = 0;
    int fd1 = open(argv[1], O_RDONLY, 0); 
    
    while((read(fd1, &c, 1)) == 1) {
        buff[i++] = c;
    }
    
    printf("%s", buff);
    exit(0); 
} 
