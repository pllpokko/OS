#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <pthread.h>
#include <sched.h>

#define NTHREADS 10
#define yiledON 0

void* ping_func()
{
	while(1)
	{
		printf("ping\n");
#ifdef yeildON
		pthread_yield();
#endif
	}
}

void* pong_func()
{
	while(1)
	{
		printf("pong\n");
#ifdef yiledON
		pthread_yield();
#endif
	}
}
int main()
{
	pthread_t th[2];

	pthread_create(&th[0],NULL,ping_func,NULL);
	pthread_create(&th[1],NULL,pong_func,NULL);



	pthread_join(th[0],NULL);
	pthread_join(th[1],NULL);

	return 0;
}
