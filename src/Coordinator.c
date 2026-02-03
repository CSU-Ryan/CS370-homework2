#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int main(const int dividend,
    const int divisor1,
    const int divisor2,
    const int divisor3,
    const int divisor4)
{
    const int[4] divisors = {divisor1, divisor2, divisor3, divisor4};

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