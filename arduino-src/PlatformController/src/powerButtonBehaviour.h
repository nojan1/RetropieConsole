#include <behaviour.h>
#include <Arduino.h>

#define POWERBTN_PIN 2
#define POWERLED_PIN 13

class PowerButtonBehaviour : public Behaviour
{
private:
    void blinkPowerLed();
public:
    PowerButtonBehaviour();
    void inStarting();
    void inShuttingDown();
    void inIdle();
    void onTransition(int from, int to);
};