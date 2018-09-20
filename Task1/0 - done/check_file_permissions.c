/*
    Checks file. If file does not exist, exit.
    If file exists, checks read and write access.
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h> 
#include <errno.h>
#include <unistd.h>

int main(int argc, char* argv[]){ 
    char* filepath = argv[1]; int returnval;
    // Check file existence 
    // CODE REDACTED

    if (returnval == 0) printf ("\n%s exists\n", filepath); 
    else { 
        if (errno == ENOENT) {
            printf("\n%s does not exist...\n", filepath);
        }
        else if (errno == EACCES) {
            printf("%s is not accessible\n", filepath);
            return 0;
        }
    }
    // Check read access ...
    // CODE REDACTED 

    if (returnval == 0) printf ("\n%s readable.\n", filepath); 
    else { 
        if (errno == ENOENT) printf("%s does not exist\n", filepath);
        else if (errno == EACCES) printf("%s is not readable\n", filepath);
        return 0;
    }

    // Check write access ...    
    // CODE REDACTED

    if (returnval == 0) printf ("\n%s in writeable.\n", filepath); 
    else { 
        if (errno == ENOENT) printf("%s does not exist\n", filepath);
        else if (errno == EACCES) printf("%s is not writable\n", filepath);
        return 0;
    }
    return 0;
}