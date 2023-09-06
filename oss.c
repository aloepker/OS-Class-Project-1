#include <stdio.h>


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
