#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>


volatile sig_atomic_t print_flag = true;
static int count = 0;

void timer_handler (int signum)
{

 printf ("timer expired %d times\n", ++count);
 if(count>20) {
    print_flag = false;
 } 
}

int main ()
{
 struct sigaction sa;
 struct itimerval timer;

 /* Install timer_handler as the signal handler for SIGVTALRM. */
 memset (&sa, 0, sizeof (sa));
 sa.sa_handler = &timer_handler;
 sigaction (SIGALRM, &sa, NULL);

 /* Configure the timer to expire after 250 msec... */
 timer.it_value.tv_sec = 1;
 timer.it_value.tv_usec = 500;
 /* ... and every 250 msec after that. */
 timer.it_interval.tv_sec = 0;
 timer.it_interval.tv_usec = 10;
 /* Start a virtual timer. It counts down whenever this process is
   executing. */
 setitimer (ITIMER_REAL, &timer, NULL);

 /* Do busy work. */
 while (print_flag) {
    sleep(1);
 }

printf("job done bye bye\n");
    exit(0);

}
