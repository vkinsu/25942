#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    pid_t proc;
    int status;

    proc = fork();

    if (proc < 0) {
        perror("fork failed");
        exit(1);
    }

    if (proc == 0){
        const char *command = argv[1];
        
        execvp(command, &argv[1]);
        perror("execvp failed");
        exit(1);
    }

    else {
        waitpid(proc, &status, 0);
        if (WIFEXITED(status)){
            printf("exit status: %d\n", WEXITSTATUS(status));
        }
        else {
            perror("failed");
            exit(1);
        }
    }
    return 0;
}
