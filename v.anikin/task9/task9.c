#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t proc;
    int status;

    proc = fork(); 

    if (proc < 0) {
        perror("fork failed");
        exit(1);
    }

    if (proc == 0) {
        execl("/usr/bin/cat","cat","file.txt",NULL);
        perror("execl failed");
        exit(1);
    }
    else {
        printf("Text printed by parent process\n");  

        waitpid(proc, &status, 0);

        printf("Text printed by parent process. Again\n");
    }

    return 0;
}
