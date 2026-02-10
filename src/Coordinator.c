#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    if (argc != 6) {
        printf("Coordinator: invalid number of arguments (%d =/= 6).\n", argc);
        return 1;
    }

    const int dividend = atoi(argv[1]);
    const int divisors[4] = {atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5])};

    for (int i = 0; i < 4; i++) {
        const int divisor = divisors[i];

        const auto pid = fork();
        if (pid == 0) {
            // Code for the Child
            printf("Coordinator [%d]: I'm the child!\n", getpid());
            execlp("./checker.o", "./checker.o", divisor, dividend);
        }
        else if (pid > 0) {
            // Code for the Parent
            printf("Coordinator [%d]: forked process with ID %d.\n", getpid(), pid);
            printf("Coordinator [%d]: waiting for process [%d].\n", getpid(), pid);

            int status;
            waitpid(pid, &status, 0);

            printf("Coordinator [%d]: child process %d returned %d.\n",
                getpid(), pid, WEXITSTATUS(status)
                );
        }
        else {
            // Failed to fork
            printf("Coordinator: could not fork child process.\n");
            return 1;
        }
    }
}