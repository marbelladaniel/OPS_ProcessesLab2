#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


main(int argc, char *argv[]){
	
	srand(time(NULL)); 
	int status;  
	int pid; 
	int i; 
	int child_sleep = (rand() %10)+1; 

	for(i = 0; i<3; i++){ 
	pid = fork(); //creates a child

 
	switch(pid) {
		case 0:		//child
			printf("Child PID  %d  is going to sleep!\n", getpid());
			sleep(child_sleep);  //use random generator 
			printf("Child PID %d  is awake, where is my parent,  %d?\n",getpid(),  getppid()); 
			exit(0);  
			break; 

		case -1: 		//error
			break; 

		default: 		//parent. PID is child's pid
			wait (&status); 	//parent wait until child terminates , then reaps the child 
			printf("Child %d,  has completed.\n"); 
			break; 

	}			

     } 

	printf("Programming terminating.\n"); 

}
