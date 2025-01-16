#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h> // unavailable for windows systems
#include <stdlib.h>

int main() {
    pid_t pid1, pid2, pid3;
    int status;

    pid1 = fork();

    if (pid1 < 0) {
        fprintf(stderr, "Fork Failed for Child1\n");
        exit(1);
    }
    else if (pid1 == 0) {
        // Child1 process
        printf("Child1 created [PID: %d] [Parent PID: %d]\n", getpid(), getppid());
        
        pid3 = fork();
        
        if (pid3 < 0) {
            fprintf(stderr, "Fork Failed for Child1's child\n");
            exit(1);
        }
        else if (pid3 == 0) {
            // Child of Child1
            printf("Child of Child1 created [PID: %d] [Parent PID: %d]\n", getpid(), getppid());
            exit(0);
        }
        else {
            // Child1 waits for its child to complete
            wait(&status);
            printf("Child1's child completed\n");
            exit(0);
        }
    }
    else {
        // Parent process creates second child (Child2)
        pid2 = fork();
        
        if (pid2 < 0) {
            // Fork failed
            fprintf(stderr, "Fork Failed for Child2\n");
            exit(1);
        }
        else if (pid2 == 0) {
            // Child2 process
            printf("Child2 created [PID: %d] [Parent PID: %d]\n", getpid(), getppid());
            exit(0);
        }
        else {
            // Parent process
            printf("Parent process [PID: %d]\n", getpid());
            
            // Wait for both children to complete
            wait(&status);
            wait(&status);
            
            printf("All child processes completed\n");
        }
    }

    return 0;
}

