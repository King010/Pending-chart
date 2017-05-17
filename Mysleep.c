
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>

void handler(int sig)
{
}

int mysleep(int seconds)
{
	struct sigaction act,oact;
	act.sa_handler=handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags=0;
	sigaction(SIGALRM,&act,&oact);

	alarm(seconds);
	pause();
	int _time=alarm(0);
	sigaction(SIGALRM,&oact,NULL);
	return _time;
}



int main()
{
	while(1)
	{
		printf("hello I am sleeping\n");
		mysleep(3);
	}
	return 0;
}
