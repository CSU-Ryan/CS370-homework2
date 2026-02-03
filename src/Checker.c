#include <stdio.h>

int main(const int divisor, const int dividend) {
    printf("Checker process [%d]: Starting.\n", getpid());

    int divides = (dividend % divisor == 0);

    printf("Checker process [%d]: %d *%S* divisible by %d.\n",
        getpid(),
        dividend,
        (divides) ? "IS" : "IS NOT",
        divisor;
        );
    printf("Checker process [%d]: Returning %d.\n", getpid(), divides);

    return divides;
}
