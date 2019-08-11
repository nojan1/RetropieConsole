#include <fanBehaviour.h>
#include <states.h>

FanBehaviour::FanBehaviour()
{
    pinMode(FAN_PIN, OUTPUT);
    analogWrite(FAN_PIN, 0);
}

void FanBehaviour::onTransition(int from, int to){
    if(to == RUNNING)
        analogWrite(FAN_PIN, 255);
    else
        analogWrite(FAN_PIN, 0);
}