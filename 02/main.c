#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc,char **argv)
{
	int pfd[2];
	int nread;
	int pid;
	char buf[BUFSIZ];

	pipe(pfd);
	pid=fork();
	if(pid==0)
	{
		close(pfd[1]);
		while((nread=read(pfd[0],buf,BUFSIZ))!=0)
		{
			printf("child read %s\n",buf);
		}
		close(pfd[0]);
	}
	else
	{
		close(pfd[0]);
		strcpy(buf,"hello..");
		write(pfd[1],buf,strlen(buf)+1);
		close(pfd[1]);
	}

	return 0;
}
