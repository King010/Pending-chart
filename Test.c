/*************************************************************************
	> File Name: test.c
	> Author: ztf
	> Mail: 379177267@qq.com 
	> Created Time: Thu 13 Apr 2017 03:51:59 PM CST
 ************************************************************************/

#include<stdio.h>
int main()
{
	while(1)
	{
		printf("my pid is %d\n",getpid());
		sleep(1);
	}
	return 0;
}
