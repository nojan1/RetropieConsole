#ifndef CLASS_BEHAVIOUR
#define CLASS_BEHAVIOUR

#include <Arduino.h>

class Behaviour
{
protected:
    unsigned long lastRun = 0;

    bool timeToRun(unsigned long delay){
        unsigned long nextRun = lastRun + delay;

        if(lastRun == 0 || nextRun <= millis()){
            lastRun = millis();
            return true;
        }

        return false;
    }
public:
    virtual void inIdle() {};
    virtual void inRunning() {};
    virtual void inStarting() {};
    virtual void inShuttingDown() {};
    virtual void inPowerOff() {};
    virtual void inError(int errorCode) {};
    virtual void onTransition(int from, int to) {};
};

#endif