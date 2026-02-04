#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(const int argc, char **argv) {
    if (argc != 2) {
        printf("Checker process [%d]: Invalid number of arguments (%d =/= 2).\n", getpid(), argc);
        return 1;
    }

    const int divisor = atoi(argv[0]);
    const int dividend = atoi(argv[1]);

    printf("Checker process [%d]: Starting.\n", getpid());

    int divides = (dividend % divisor == 0);

    printf("Checker process [%d]: %d *%S* divisible by %d.\n",
        getpid(),
        dividend,
        (divides) ? "IS" : "IS NOT",
        divisor
        );
    printf("Checker process [%d]: Returning %d.\n", getpid(), divides);

    return divides;
}
