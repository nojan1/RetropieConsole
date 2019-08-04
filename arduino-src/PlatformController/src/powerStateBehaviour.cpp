#include <powerStateBehaviour.h>
#include <states.h>

PowerStateBehaviour::PowerStateBehaviour()
{
    pinMode(ARDUINOPOWER_PIN, OUTPUT);
    pinMode(PIPOWER_PIN, OUTPUT);

    digitalWrite(ARDUINOPOWER_PIN, HIGH);
    digitalWrite(PIPOWER_PIN, LOW);


    timeToRun(100);
}

//TEMP: Fake PI startup
void PowerStateBehaviour::inIdle(){
    timeToRun(0);
}

void PowerStateBehaviour::inStarting()
{
    digitalWrite(PIPOWER_PIN, HIGH);

    //TEMP: Fake PI startup
    if(timeToRun(3500))
        setState(RUNNING);
}

void PowerStateBehaviour::inPowerOff()
{
    digitalWrite(PIPOWER_PIN, LOW);
    digitalWrite(ARDUINOPOWER_PIN, LOW);
}