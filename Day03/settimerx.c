#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

#define INTERVAL 1        /* number of milliseconds to go off */

int main() {
    double sum = 0;
    struct itimerval initial, updated;

    initial.it_value.tv_sec     = INTERVAL;
    initial.it_value.tv_usec    = 999999;
    initial.it_interval = initial.it_value;
    memcpy(&(initial.it_interval), &(initial.it_value), sizeof( initial.it_value )); 
    printf("%ld\n", initial.it_value.tv_usec);

    if (setitimer(ITIMER_VIRTUAL, &initial, NULL) == -1) {
        perror("error calling setitimer()");
        exit(1);
    }

    for (unsigned int i; i < 100; i++) 
        sum += 1./i;

    if (getitimer(ITIMER_REAL, &updated) == -1) {
        perror("error calling getitimer()");
        exit(1);
    }

    printf("Time started = %ld\n; Time ended = %ld\n: Time taken = %ld\n",
           initial.it_value.tv_usec, updated.it_value.tv_usec,
           initial.it_value.tv_usec - updated.it_value.tv_usec);
    return 0;
}
