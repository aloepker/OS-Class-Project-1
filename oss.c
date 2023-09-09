#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void help(){
printf("The options for the program are:\n");
printf("-n <number>   this sets the number of processes to launch\n");
printf("-s <number>   this sets how many processes can run at once\n");
printf("-t <number>   this sets the number of loops the worker(s) perform\n");

}

int main(int argc, char** argv){
int option;
int numWorkers = 0;
int workerLimit = 0;
int iter = 0;

while((option = getopt(argc, argv, "hn:s:t:")) != -1){
	switch(option){
		case 'h':
			help();
			return EXIT_SUCCESS;
		case 'n':
			numWorkers = atoi(optarg);
			break;
		case 's':
			workerLimit = atoi(optarg);
			break;
		case 't':
			iter = atoi(optarg);
			break;
		case '?':
			if ((optopt = 'c'))
				printf("Option %c requires an argument\n", optopt);
			else if (isprint(optopt))
				printf("Unknown Character '\\x%x'.\n", optopt);
			return 1;
		default:
			help();
			return EXIT_SUCCESS;
	}


}

printf("Number of workers Selected:%d\nNumber of Workers at a time:%d\nNumber of loops for each Worker:%d\n", numWorkers, workerLimit, iter);
printf("Now we are cooking!\n");

pid_t childPid = fork();
if (childPid == 0) {

char argString[20];
sprintf(argString, "%d", iter);

execl("./worker","./worker", argString, NULL);

} else {
int stat;
wait(&stat);
printf("Wait opperation compleated successfully!\n");
}


}

// this program will launch a certian number of worker processes with certian parameters.
// the number launched is based on pased arguments

//will be inkoked with the following: oss [-h] [-n proc] [-s simul] [-t iter]
// proc is total number of children to launch
//iter is number to pass to worker for its loop
// simul indicates how many child precesses  are allowed to run simultaneously

//ex: to launch oss w/5 workers, only upto 3 at a time, w/ 7 iterations in their loops:
//oss -n -n 5 -s 3 -t 7

// -h parameter should output a usage statemtent and terminate


//oss:
// when launched should enter a loop, do a fork() and exec() to call the worker process,
//this should only occur upto the simul argument, then wait() before performing the next till done
