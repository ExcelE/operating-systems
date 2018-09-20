/*
    This program takes in 2 arguments. 1st is an existing file and 
    2nd is a non existing file. 1st's contents will be read and 
    copied over to the 2nd.

    Errors handled: 
        - if file 1 does not exists, error - no such file
        - if file 2 exists already, error - file already exists
        - if file 1 does not have read permissions
*/
#include<stdio.h> 
#include<fcntl.h> 
#include<errno.h> 
#include<stdlib.h>
#include<string.h>
extern int errno; 

int main(int argc, char* argv[]) 
{      
    int first = open(argv[1], O_RDONLY);  
    int second = open(argv[2], O_RDONLY);  
      
    // Check:
    //  - For existance of 1nd file
    //  - For existance of 2nd file
    if (first == -1) { 
        // print which type of error have in a code 
        printf("Error Number % d\n", errno);  
        // print program detail "Success or failure" 
        perror("Program");            
        exit(1);      
    } 
    if (second > 0) {
        printf("File already exists!");
        close(first);
        close(second);
        exit(1);      
    }

    // Create 2nd file, 0777 is the permission bits to be able to read the file.
    int destination = open(argv[2], O_CREAT, 0777);  
    close(destination);

    // Copy contents of first to a buffer.
    int i = 0; char* buff; char c;
    while((read(first, &c, 1)) == 1) {
        buff[i++] = c;
    }

    // Writes buffer to second
    int second_file = open(argv[2], O_RDWR);
    int sz = write(second_file, buff, strlen(buff)); 

    if (sz > 0) {
        printf("%s copied to %s successfully!", argv[1], argv[2]);
    } else {
        printf("%s\n", buff);
        printf("Error Number % d\n", errno);  
        // print program detail "Success or failure" 
        perror("Program"); 
    }
    close(first);
    close(second_file);

    return 0; 
} 
