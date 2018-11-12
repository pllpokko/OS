#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main(char *prog,char **args)
{
	int n;
	pid_t new_pid;
	/*
	new_pid=fork();
	char *message;
	int exit_code;
	int child_pid;
	// Read and parse the input a line at a time
while (readAndParseCmdLine(&prog, &args)) {
	child_pid= fork(); // create a child process
	if (child_pid== 0) {
		exec(prog, args); // I'm the child process. Run program
		// NOT REACHED
	} else {
		wait(child_pid); // I'm the parent, wait for child
		return 0;
	}
	}*/

	for(int i=0;i<3;i++)
	{
		fork();
		printf("%d hello\n",getpid());
	}

	exit(1);
}
