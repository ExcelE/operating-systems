/*
    This program takes in 2 arguments. 1st is an existing file and 
    2nd is a non existing file. 1st's contents will be read and 
    copied over to the 2nd. Replaces '1' with 'A';

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

    // Copy contents of first 100 char to a buffer.
    int status = 1;
    while (status == 1){
        int origCharCount, newCharCount = 0;  
        char* buff; char c;
        while((status = read(first, &c, 1)) == 1 && origCharCount < 100) {
            if (c == '1') {
                buff[newCharCount++] = 'A';
                buff[newCharCount++] = 'X';
                buff[newCharCount++] = 'Y';
                buff[newCharCount++] = 'Z';
            } else {
                buff[newCharCount++] = c;
            }
            origCharCount++;
        }

        // Writes buffer to second
        int second_file = open(argv[2], O_WRONLY | O_APPEND);
        int sz = write(second_file, buff, strlen(buff)); 

        if (sz < 0) {
            printf("%s\n", buff);
            printf("Error Number % d\n", errno);  
            // print program detail "Success or failure" 
            perror("Program"); 
        }
        close(second_file);
        memset(&buff[0], 0, sizeof(buff));
        origCharCount = 0;
    }

    close(first);

    return 0; 
} 
