#include <behaviour.h>
#include <pins.h>
#include <Arduino.h>

class PowerButtonBehaviour : public Behaviour
{
private:
    void blinkPowerLed();
public:
    PowerButtonBehaviour();
    void inStarting();
    void inShuttingDown();
    void inRunning();
    void inIdle();
    void onTransition(int from, int to);
};