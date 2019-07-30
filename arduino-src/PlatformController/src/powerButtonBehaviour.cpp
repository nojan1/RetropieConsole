#include <powerButtonBehaviour.h>

void PowerButtonBehaviour::blinkPowerLed(){
    if(timeToRun(200)){
        digitalWrite(POWERLED_PIN, !digitalRead(POWERLED_PIN));
    }
}

PowerButtonBehaviour::PowerButtonBehaviour()
{
    pinMode(POWERBTN_PIN, INPUT_PULLUP);
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

void PowerButtonBehaviour::inError(int errorCode)
{

}

void PowerButtonBehaviour::onTransition(int from, int to)
{
    digitalWrite(POWERLED_PIN, HIGH);
}