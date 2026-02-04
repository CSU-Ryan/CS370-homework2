#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    if (argc != 5) {
        printf("Coordinator: invalid number of arguments.\n");
        return 1;
    }

    const int dividend = atoi(argv[0]);
    const int[4] divisors = {atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4])};

    for (int i = 0; i < 4; i++) {
        const int divisor = divisors[i];

        const auto pid = fork();
        if (pid == 0) {
            // Code for the Child
            execlp("/bin/checker.o", "/bin/checker.o", divisor, dividend);
        }
        else if (pid > 0) {
            // Code for the Parent
            int status;
            wait(&status);

            printf("Coordinator: child process %d returned %d.\n",
                pid, WEXITSTATUS(status)
                );
        }
        else {
            // Failed to fork
            printf("Coordinator: could not fork child process.\n");
            return 1;
        }
    }
}