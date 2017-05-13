#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<signal.h>


void hander(int sig)
{
	printf("get a sig%d\n",sig);
}

void show_pending(sigset_t *pending)
{
	int i=1;
	for(;i<=31;i++)
	{
		if(sigismember(pending,i))
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	}
	printf("\n");
}


int main()
{
	signal(2,hander);
	sigset_t block,oblock,pending;
	sigemptyset(&block);
	sigemptyset(&oblock);
	sigemptyset(&pending);
	sigaddset(&block,2);
	sigprocmask(SIG_SETMASK,&block,&oblock);

	int count=0;
	while(1)
	{
		sigpending(&pending);
		sleep(1);
		show_pending(&pending);
		if(count==10)
		{
			sigprocmask(SIG_SETMASK,&oblock,NULL);
		}
		count++;
	}
	return 0;
}





//int main(int argc,char *argv[])
//{
	
//	kill(atoi(argv[1]),2);
//	return 0;
//}






//int main(int argc,char *argv[])
//{
//	signal(2,hander);	
//	while(1)
//	{
//		printf("hello world\n");
//		sleep(1);
//	}
//	return 0;
//}
