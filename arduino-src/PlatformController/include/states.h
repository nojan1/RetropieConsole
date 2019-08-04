#ifndef STATES
#define STATES

#define IDLE 0
#define STARTING 1
#define RUNNING 2
#define SHUTTINGDOWN 3
#define ERROR 4
#define POWEROFF 5

void setState(int state, int errorCode = -1);

//Error codes
#define ERROR_DISPLAYALLOC 1

#endif