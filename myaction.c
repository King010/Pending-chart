#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<signal.h>
#include<stdlib.h>


void handler(int sig)
{
	printf("get a sig %d\n",sig);
}

int main()
{

	struct sigaction act,oact;
	act.sa_handler=handler;
	sigemptyset(&act.sa_mask);

	sigaction(2,&act,&oact);
	while(1)
	{
		printf("hello world\n");
		sleep(1);
	}
	return 0;
}
