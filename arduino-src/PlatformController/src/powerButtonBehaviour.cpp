#include <powerButtonBehaviour.h>
#include <states.h>

void PowerButtonBehaviour::blinkPowerLed(){
    if(timeToRun(200)){
        digitalWrite(POWERLED_PIN, !digitalRead(POWERLED_PIN));
    }
}

PowerButtonBehaviour::PowerButtonBehaviour()
{
    pinMode(POWERBTN_PIN, INPUT);
    pinMode(POWERLED_PIN, OUTPUT);

    digitalWrite(POWERLED_PIN, HIGH);
}

void PowerButtonBehaviour::inStarting()
{
    blinkPowerLed();
}

void PowerButtonBehaviour::inShuttingDown()
{
    blinkPowerLed();
}

void PowerButtonBehaviour::inRunning()
{
    digitalWrite(POWERLED_PIN, LOW);

    if(digitalRead(POWERBTN_PIN) == HIGH){
        //TODO: Send command to pi to make it halt
        setState(SHUTTINGDOWN);
    }
}


void PowerButtonBehaviour::inIdle()
{
    if(digitalRead(POWERBTN_PIN) == HIGH){
        setState(STARTING);
    }
}

void PowerButtonBehaviour::onTransition(int from, int to)
{
    digitalWrite(POWERLED_PIN, HIGH);
}