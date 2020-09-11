/*
	Name: Chukwudi Ikem
	Class: CPSC 351 - Operating Systems
	Assignment: Homework #1
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>


/**
 * The function to be executed by the child
 */
void child()
{
		
	/** NOTE: getpid() returns the process id of the caller process **/
	printf("Hi! I am the child. My pid is %d. I am immortal!\n", getpid());

	// MY ANSWER
	/* 
		2.) Because execlp("yes", "yes", NULL); never returns a value, it halts the entire program.
		The if statement is not able to fully resolve. Due to this fact, the child process never resolves.
		Since the child process never resolves, we do not see anything meaningful print to the screen. 

		The first printf in this child process does in fact run. The issue is that the infinite loop comes
		right afterwards. If we put the execution on pause for a second, we can see that the initial message
		prints successfully.
	*/
	
	/*
	sleep(4);

	if(execlp("yes", "yes", NULL) < 0)
	{
		perror("execlp");
		exit(-1);
	}
	*/
		
}

int main(int argc, char** argv)
{
	/* The process id of the child */
	pid_t child_pid;
	
	/* If the fork failed, then terminate. Otherwise, save the  
	 * value returned by fork(). 
	 */
	if((child_pid = fork()) < 0)
	{
		perror("fork");
		exit(-1);
	}
	
	/* Are we a child process ? */
	if(child_pid == 0)
	{
		/* Call the child function */
		child();
	}
	/* We are the parent */
	else
	{
		wait(NULL); // 2.) going to wait for the child process to complete.
		fprintf(stderr, "Hi! I am a parent. Just created a child with pid %d\n", child_pid);
		fprintf(stderr, "I will live for 60 seconds. My child shall live forever!");

		/* Wait for 60 seconds, then die. NEVER CALL WAIT */
		sleep(60);
		
		exit(0);
	
	}	
	return 0;
}
