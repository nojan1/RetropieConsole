#ifndef STATES
#define STATES

#define IDLE 0
#define STARTING 1
#define RUNNING 2
#define SHUTTINGDOWN 3
#define ERROR 4

void setState(int state, int errorCode = -1);

#endif