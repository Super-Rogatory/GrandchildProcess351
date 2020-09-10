#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	pid_t pid, cpid;
	pid = fork();
	if (pid < 0) {
		fprintf(stderr, "Fork Failed");
		exit(-1);
	}

	// create a child
	if(pid == 0) {
		cpid = fork(); // creates a grandchild, executes a command.
		if(cpid == 0) {
			execlp("/bin/ls", "ls", NULL); 
		}
		wait(NULL); //ensures the grandchild does not go zombie.
		printf("\n Grandchild Complete \n");
		sleep(2); //for dramatic effect
		execlp("/bin/ls", "ls", NULL);
	} 
	else {
		wait(NULL);
		printf("\n Child Complete \n");
		exit(0);
	}
	
}
